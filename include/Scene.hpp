#ifndef __IDEA_ENGINE_SCHENE_H__
#define __IDEA_ENGINE_SCHENE_H__

#include <vector>

#include "spdlog/spdlog.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
#include "SDL.h"
#else
#include <SDL2/SDL.h>
#endif

#include "Object.hpp"
#include "Camera.hpp"

namespace IdeaEngine {
class Scene {
public:
    Scene(const std::string& id, SDL_Renderer* renderer, std::shared_ptr<spdlog::logger> log);
    ~Scene();
    void addObject(Object* _object);
    void addScene(std::shared_ptr<Scene> scene);
    void Render(Camera* camera);

private:
    SDL_Renderer* _renderer;
    std::vector<std::shared_ptr<Scene>> _scenes;
    std::vector<Object*> _objects;
    std::shared_ptr<spdlog::logger> _log;
    std::string _id;
};

    std::shared_ptr<Scene> NewScene(const std::string& id, SDL_Renderer *renderer);
};

#endif
