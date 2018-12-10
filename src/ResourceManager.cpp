#include "ResourceManager.hpp"

namespace IdeaEngine {

ResourceManager::ResourceManager(SDL_Renderer* renderer, std::shared_ptr<spdlog::logger> log) :
  _renderer(renderer),
  _log(log)
{
  
}

ResourceManager::~ResourceManager()
{

}

Texture* ResourceManager::texture(const std::string& id)
{
  try {
    auto tx = _textures.at(id);
    return tx;
  } catch (std::out_of_range& ex) {
    auto tx = loadTexture(id);
    if (tx == nullptr) {
      _log->error("Can't get texture {0}", id);
    }
    return tx;
  }
}


Texture* ResourceManager::loadTexture(const std::string& path)
{
  Texture* texture = new Texture(_renderer, _log);
  if (!texture->load(path)) 
  {
    _log->error("Failed to load texture from {0}", path);
    return nullptr;
  }

  _textures.insert(std::pair<std::string, Texture*>(path, texture));
  return texture;
}

}