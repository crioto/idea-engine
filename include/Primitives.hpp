#ifndef __PRIMITIVES_HPP__
#define __PRIMITIVES_HPP__

#include "spdlog/spdlog.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
#include <SDL.h>
#include <SDL_image.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

#include "Object.hpp"

namespace IdeaEngine {
class Primitives : public Object {
public:
    Primitives(const std::string& id, SDL_Renderer* renderer, int x, int y, int w, int h, SDL_Color color, std::shared_ptr<spdlog::logger> log);
    ~Primitives();
    virtual void render(Camera* camera) = 0;
    void setColor(SDL_Color color);

    SDL_Color color();

protected:
    SDL_Color _color;
};
}

#endif