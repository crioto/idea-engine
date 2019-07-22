#ifndef __IDEA_ENGINE_ENGINE_H__
#define __IDEA_ENGINE_ENGINE_H__

#include <iostream>
#include <string>
#include <vector>
#include <deque>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include "CommandInterface.hpp"
#include "Event.hpp"
#include "Level.hpp"
#include "Object.hpp"
#include "Scene.hpp"
#include "Seed.hpp"
#include "Simulation.hpp"
#include "Camera.hpp"
#include "ResourceManager.hpp"

///
/// \namespace IdeaEngine 
/// \brief Main namespace of the engine
/// 
namespace IdeaEngine {

///
/// \class Engine
/// \brief Main class of the engine
///
class Engine {
public:
    Engine(std::vector<std::string> args);
    ~Engine();
    void initialize();
    void deinitialize();
    // run starts main loop
    int run();
    void enableConsole();
    // getWindowWidth returns width of the window
    int getWindowWidth();
    // getWindowHeight returns height of the window
    int getWindowHeight();
    // renderer returns a SDL_Renderer reference
    SDL_Renderer* renderer();
    // scene returns top-level scene of the game
    Scene* scene();
    // simulation returns simulation
    Simulation* simulation();
    // event returns event subsystem
    Event* event();
    // cli will return command interface
    CommandInterface* cli();
    // camera will return camera
    Camera* camera();
    // addToQueue will add object to loading queue
    void addToQueue(Object* obj);
    // log returns logger
    std::shared_ptr<spdlog::logger> log();
    // manager will return ResourceManager
    ResourceManager* manager();
protected:
    void loadFromQueue(); 
private:
    std::vector<std::string> _args; ///< Command line arguments provided at startup
    SDL_Window* _window = NULL; ///< SDL Window object. Created during initialization
    SDL_Renderer* _renderer = NULL; ///< SDL Renderer object. Created during initialization
    Scene* _scene; ///< Top-level scene, that contains sub-scenes. See Scene class
    Event* _event; ///< Pointer to event subsystem. See Event class
    Camera* _camera; ///< Game camera. See Camera
    ResourceManager* _manager; ///< Manager of game resources. See ResourceManager
    Simulation* _sim; ///< Simulation controller. See Simulation
    bool _running; ///< Whether engine is running or not
    CommandInterface* _command; ///< Command-line interface for game console
    std::shared_ptr<spdlog::logger> _log; ///< Logging subsystem
    int _windowWidth; ///< Window width
    int _windowHeight; ///< Window height
    std::deque<Object*> _loadingQueue; ///< Queue of game resources to be loaded on each frame
};
}

#endif
