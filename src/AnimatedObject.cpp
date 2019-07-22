#include "AnimatedObject.hpp"

namespace IdeaEngine {
  AnimatedObject::AnimatedObject(const std::string& id, ResourceManager* manager, SDL_Renderer* renderer, const std::string& filename, std::shared_ptr<spdlog::logger> log) :
    Object(id, manager, renderer, filename, log)
  {
  }

  AnimatedObject::~AnimatedObject()
  {

  }

  bool AnimatedObject::load()
  {
    Object::load();

    return true;
  }

  void AnimatedObject::createFrames(const std::string& frameDataFile)
  {
    if (!_loaded || _texture == nullptr) return;
    _log->info("Creating frames for {0}", _id);

  }
}
