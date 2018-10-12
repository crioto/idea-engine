#ifndef __BUILDING_H__
#define __BUILDING_H__

#include <vector>
#include "Object.hpp"

namespace Engine
{
    class Building 
    {
        public:
        Building(SDL_Renderer* renderer, int seed, int x, int y);
        ~Building();
        void generate();
        void render();
        private:
        std::vector<Object*> _objects;
        int _x;
        int _y;
        int _seed;
        SDL_Renderer* _renderer;
    };
}

#endif