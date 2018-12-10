#ifndef __IDEA_ENGINE_TEXTURE_H__
#define __IDEA_ENGINE_TEXTURE_H__

#include "spdlog/spdlog.h"

#include <string>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
#include <SDL.h>
#include <SDL_image.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif


namespace IdeaEngine 
{
    class Texture 
    {
        public:
        Texture(SDL_Renderer* renderer, std::shared_ptr<spdlog::logger> log);
        ~Texture();
        bool load(const std::string& path);
        SDL_Texture* get();
        int width();
        int height();
        const std::string& id() const;
        private:
        SDL_Renderer* _renderer;
        std::shared_ptr<spdlog::logger> _log;
        std::string _filename;
        SDL_Texture* _texture;
        int _width;
        int _height;
    };
}

#endif