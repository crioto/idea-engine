#ifndef __ANIMATED_OBJECT_HPP__
#define __ANIMATED_OBJECT_HPP__

#include "Object.hpp"
#include "ResourceManager.hpp"

#include "yaml-cpp/yaml.h"

namespace IdeaEngine {

  class AnimatedObject : public Object {
    public:
      AnimatedObject(const std::string& id, ResourceManager* manager, SDL_Renderer* renderer, const std::string& filename, std::shared_ptr<spdlog::logger> log);
      ~AnimatedObject();
      bool load();
    private:
      void createFrames(const std::string& frameDataFile);
  };
}

#endif