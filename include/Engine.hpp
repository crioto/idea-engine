#ifndef __ENGINE_H__
#define __ENGINE_H__

#include <iostream>
#include <vector>
#include <string>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include "Scene.hpp"
#include "Object.hpp"
#include "Console.hpp"
#include "Event.hpp"
#include "Building.hpp"
#include "Event.hpp"
#include "Simulation.hpp"
#include "Level.hpp"
#include "Seed.hpp"

namespace Engine 
{
    class Engine 
    {
        public:
        Engine(std::vector<std::string> args);
        ~Engine();
        void initialize();
        void deinitialize();
        int run();
        private:
        std::vector<std::string> _args;
        SDL_Window* _window = NULL;
		SDL_Renderer* _renderer = NULL;
        SDL_Surface* _surface = NULL;
        Simulation* _sim;
        bool _running;
    };
}

#endif