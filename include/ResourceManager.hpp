#ifndef __RESOURCE_MANAGER_HPP__
#define __RESOURCE_MANAGER_HPP__

#include <map>

#include "spdlog/spdlog.h"

#include "Texture.hpp"
#include "Font.hpp"

namespace IdeaEngine {

  class ResourceManager {
    public:
      ResourceManager(SDL_Renderer* renderer, std::shared_ptr<spdlog::logger> log);
      ~ResourceManager();
      Texture* texture(const std::string& id);
    private:
      Texture* loadTexture(const std::string& path);
      SDL_Renderer* _renderer;
      std::shared_ptr<spdlog::logger> _log;
      std::map<std::string, Texture*> _textures;
  };
};

#endif