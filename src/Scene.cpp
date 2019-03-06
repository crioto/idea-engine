#include "Scene.hpp"

namespace IdeaEngine {

std::shared_ptr<Scene> NewScene(const std::string& id)
{
    auto scene = std::make_shared<Scene>(id, spdlog::get("idea"));
    return scene;
}

Scene::Scene(const std::string& id, std::shared_ptr<spdlog::logger> log)
    : _log(log)
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


void Scene::render(Camera *camera)
{
    for (auto it = _objects.begin(); it != _objects.end(); it++) {
        (*it)->render(camera);
    }

    for (auto it = _scenes.begin(); it != _scenes.end(); it++) {
        (*it)->render(camera);
    }
}

std::vector<Object*> Scene::findObjects(int x, int y) {
    std::vector<Object*> result;
    for (auto it = _objects.begin(); it != _objects.end(); it++) {
        int ox = (*it)->x();
        int ow = (*it)->width() + ox;
        int oy = (*it)->y();
        int oh = (*it)->height() + oy;
        if (ox <= x && ow >= x && oy <= y && oh >= y) {
            result.push_back((*it));
        } 
    }
    return result;
}

}
