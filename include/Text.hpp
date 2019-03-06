#ifndef __IDEA_ENGINE_TEXT_HPP__
#define __IDEA_ENGINE_TEXT_HPP__

#include "Object.hpp"
#include "Font.hpp"

namespace IdeaEngine {
  class Text : public Object {
    public:
      Text(const std::string& id, ResourceManager* manager, SDL_Renderer* renderer, const std::string& filename, std::shared_ptr<spdlog::logger> log);
      ~Text();
      void setColor(SDL_Color color);
      bool load();
      void render(Camera* camera);
      void update();
    private:
      Font* _font;
      SDL_Texture* _texture;
      SDL_Color _color;
  };
}

#endif