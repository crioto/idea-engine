#ifndef __SCHENE_H__
#define __SCHENE_H__

#include <vector>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
#include "SDL.h"
#else
#include <SDL2/SDL.h>
#endif

#include "Object.hpp"

namespace Engine {
    class Scene {
    public:
        Scene(SDL_Renderer* renderer);
        ~Scene();
        void addObject(Object* _object);
        void Render();
    private:
        SDL_Renderer* _renderer;
        std::vector<Object*> _objects;
    };
};

#endif
