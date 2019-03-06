#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "Primitives.hpp"

namespace IdeaEngine {
  class Rectangle : public Primitives
  {
    public:
      Rectangle(const std::string& id, SDL_Renderer* renderer, int x, int y, int w, int h, SDL_Color color, std::shared_ptr<spdlog::logger> log);
      ~Rectangle();
      void render(Camera* camera);
      
    private:
      SDL_Rect _rect;
  };
}

#endif