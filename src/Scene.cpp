#include "Scene.hpp"

namespace Engine {
    Scene::Scene(SDL_Renderer* renderer) : _renderer(renderer) 
    {

    }

    Scene::~Scene()
    {

    }

    void Scene::addObject(Object* object)
    {
        _objects.push_back(object);
    }

    void Scene::Render()
    {
        for (auto it = _objects.begin(); it != _objects.end(); it++)
        {
            (*it)->Render();
        }
    }
}