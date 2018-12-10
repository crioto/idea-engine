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

namespace IdeaEngine {
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
    std::vector<std::string> _args;
    SDL_Window* _window = NULL;
    SDL_Renderer* _renderer = NULL;
    Scene* _scene;
    Event* _event;
    Camera* _camera;
    ResourceManager* _manager;
    // SDL_Surface* _surface = NULL;
    Simulation* _sim;
    bool _running;
    CommandInterface* _command;
    std::shared_ptr<spdlog::logger> _log;
    int _windowWidth;
    int _windowHeight;
    std::deque<Object*> _loadingQueue;
};
}

#endif
