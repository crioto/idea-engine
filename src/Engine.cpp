#include "Engine.hpp"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
#include "SDL.h"
#include "SDL_ttf.h"
#else
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#endif

namespace IdeaEngine {

//! Constructor
/**
 * Constructor initializes logging subsystem and Simulation
 *
 * \param vector<string> of arguments
 */
Engine::Engine(std::vector<std::string> args)
{
    _windowWidth = 1024;
    _windowHeight = 768;

    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::debug);
    
    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("idea-engine.log", true);
    file_sink->set_level(spdlog::level::trace);

    _log = std::make_shared<spdlog::logger>("idea", console_sink );
    _log->sinks().push_back(file_sink);
    _log->set_level(spdlog::level::debug);
    _log->info("Initializing engine");
    spdlog::register_logger(_log);

    _args = args;
    _running = false;
    _sim = new Simulation();
}

//! Destructor
Engine::~Engine()
{
    _log->info("Cleaning up");
    delete _command;
    delete _scene;
    delete _event;
    delete _manager;
    delete _camera;
    TTF_Quit();
    SDL_Quit();
}

//! Engine initializer
/**
 * This method should be called explicitely after Engine object creation
 *
 * initialize will init SDL2, SDL2 hinting, create window and renderer
 * Also it initializes font system (SDL) and set of essential objects
 */
void Engine::initialize()
{
    _log->info("Initializing SDL");
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        _log->critical("Failed to initialize SDL2: {0}", SDL_GetError());
        return;
    }

    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        _log->critical("Failed to initialize SDL2 hinting: {0}", SDL_GetError());
        return;
    }

    if ((_window = SDL_CreateWindow("My SDL Game", SDL_WINDOWPOS_UNDEFINED,
             SDL_WINDOWPOS_UNDEFINED, _windowWidth, _windowHeight,
             SDL_WINDOW_SHOWN))
        == NULL) {
        _log->critical("Failed to initialize SDL2 window: ", SDL_GetError());
        return;
    }

    // _surface = SDL_GetWindowSurface(_window);

    if ((_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED)) == NULL) {
        _log->critical("Failed to create SDL Renderer: ", SDL_GetError());
        return;
    }

    if (TTF_Init() < 0) {
        _log->critical("Failed to initialize TTF: ", TTF_GetError());
        return;
    }

    SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x88, 0xFF);

    _manager = new ResourceManager(_renderer, _log);
    _scene = new Scene("top-level", _log);
    _event = new Event();
    _camera = new Camera(_windowWidth, _windowHeight);
    _command = new CommandInterface("cli", this);
    _event->subscribe(_command);
    _log->info("Initialization complete");
}

//! Deinitizing of the engine
void Engine::deinitialize() { _log->info("Deinitializing engine"); }

//! Main game loop
int Engine::run()
{
    if (_scene == nullptr) {
      _log->critical("Top-level scene is null. Forgot to initalize?");
        return -1;
    }
    
    SDL_Event event;
    _running = true;
    _log->info("Starting main loop");
    Uint32 wait = 1000.0f/30;
    Uint32 frameStart = 0;
    Sint32 delay;
    while (_sim->getState() != SIM_SHUTDOWN) {
        while (SDL_PollEvent(&event)) {
            _event->process(&event);
        }
        SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x88, 0xFF);
        SDL_RenderClear(_renderer);
        _scene->render(_camera);
        _command->Render();
        SDL_RenderPresent(_renderer);
        delay = wait - (SDL_GetTicks() - frameStart);
        if (delay > 0) {
            SDL_Delay((Uint32)delay);
        }
        frameStart = SDL_GetTicks();
        loadFromQueue();
    }
    deinitialize();
    return 0;
}

void Engine::enableConsole() {}

//! Returns window width
/**
 * \return int Window width
 */
int Engine::getWindowWidth()
{
    return _windowWidth;
}

//! Returns window height
/**
 * \return int Window height
 */
int Engine::getWindowHeight()
{
    return _windowHeight;
}

//! Returns reference to SDL_Renderer
/**
 * \return SDL_Renderer Active Renderer
 */
SDL_Renderer* Engine::renderer() { return _renderer; }

//! Returns reference to top-level Scene
/*
 * \return Scene Top Level Scene
 */
Scene* Engine::scene() { return _scene; }

Simulation* Engine::simulation() { return _sim; }

Event* Engine::event() { return _event; }

CommandInterface* Engine::cli() { return _command; }

Camera* Engine::camera() { return _camera; }

void Engine::addToQueue(Object* obj)
{
    if (obj == nullptr) {
        _log->warn("Attempt to add null object to queue");
        return;
    }
    _log->info("Adding object {0} to queue", obj->id());
    _loadingQueue.push_back(obj);
}

void Engine::loadFromQueue()
{
    if (_loadingQueue.size() == 0) return;
    auto obj = _loadingQueue.front();
    if (obj == nullptr) return;
    obj->load();
    _loadingQueue.pop_front();
}

std::shared_ptr<spdlog::logger> Engine::log()
{
    return _log;
}

ResourceManager* Engine::manager()
{
    return _manager;
}

}
