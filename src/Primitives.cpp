#include "Primitives.hpp"

namespace IdeaEngine {

Primitives::Primitives(const std::string& id, SDL_Renderer* renderer, int x, int y, int w, int h, SDL_Color color, std::shared_ptr<spdlog::logger> log)
    : Object(id, nullptr, renderer, "", log)
{
    _x = x;
    _y = y;
    _w = w;
    _h = h;
    _color = color;
}

Primitives::~Primitives()
{
}


void Primitives::setColor(SDL_Color color)
{
    _color = color;
}

SDL_Color Primitives::color()
{
    return _color;
}

}