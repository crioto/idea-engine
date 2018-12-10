#include "Scene.hpp"

namespace IdeaEngine {

std::shared_ptr<Scene> NewScene(const std::string& id, SDL_Renderer* renderer)
{
    auto scene = std::make_shared<Scene>(id, renderer, spdlog::get("idea"));
    return scene;
}

Scene::Scene(const std::string& id, SDL_Renderer* renderer, std::shared_ptr<spdlog::logger> log)
    : _renderer(renderer)
    , _log(log)
    , _id(id)
{
    _log->info("Initializing new scene {0}", _id);
}

Scene::~Scene() 
{
  _log->info("Destroying scene {0}", _id);
}

void Scene::addObject(Object* object)
{
    if (object == nullptr) {
      _log->warn("Can't add null object to the scene {0}", _id);
      return;
    }
    _log->info("Adding new object {0} to the scene {1}", object->id(), _id);
    _objects.push_back(object);
}

void Scene::addScene(std::shared_ptr<Scene> scene) {
    _scenes.push_back(std::move(scene));
}

void Scene::Render(Camera *camera)
{
    if (_renderer == nullptr)
        return;

    for (auto it = _objects.begin(); it != _objects.end(); it++) {
        (*it)->Render(camera);
    }

    for (auto it = _scenes.begin(); it != _scenes.end(); it++) {
        (*it)->Render(camera);
    }
}
}
