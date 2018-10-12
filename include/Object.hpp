#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <iostream>
#include <string>
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
#include <SDL.h>
#include <SDL_image.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

namespace Engine {
    class Object {
        public:
        Object(SDL_Renderer *renderer, const std::string& filename);
        ~Object();
        bool Load();
        void setPosition(int x, int y);
        void Render();
        private:
        std::string _filename;
        SDL_Renderer *_renderer;
        SDL_Texture *_texture;
        int _width;
        int _height;
        int _x;
        int _y;
    };
};

#endif