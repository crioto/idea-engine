#include "AnimatedObject.hpp"

namespace IdeaEngine {
  AnimatedObject::AnimatedObject(const std::string& id, ResourceManager* manager, SDL_Renderer* renderer, const std::string& filename, std::shared_ptr<spdlog::logger> log) :
    Object(id, manager, renderer, filename, log)
  {

  }

  AnimatedObject::~AnimatedObject()
  {

  }

  void AnimatedObject::Load()
  {
    Object::Load();


  }

  void AnimatedObject::createFrames(const std::string& frameDataFile)
  {
    if (!_loaded || _texture == nullptr) return;
    _log->info("Creating frames for {0}", _id);

    
  }
}