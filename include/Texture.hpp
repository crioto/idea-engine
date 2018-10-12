#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <string>
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

namespace Engine 
{
    class Texture 
    {
        public:
        Texture(SDL_Renderer* renderer);
        ~Texture();
        bool Load(const std::string& filename);
        void Render();
        void setX();
        private:
        SDL_Renderer* _renderer;
        std::string _filename;
        int _width;
        int _height;
        int _x;
        int _y;
    };
}

#endif