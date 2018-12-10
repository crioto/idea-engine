#include "Object.hpp"
#include "Engine.hpp"

namespace IdeaEngine {

Object* NewObject(const std::string& id, Engine* engine, const std::string& filename)
{
    Object* obj = new Object(id, engine->manager(), engine->renderer(), filename, spdlog::get("idea"));
    if (!obj->Load()) {
        delete obj;
        return nullptr;
    }
    return obj;
}

Object* NewObjectInQueue(const std::string& id, Engine* engine, const std::string& filename)
{
    if (engine == nullptr) {
        return nullptr;
    }
    Object* obj = new Object(id, engine->manager(), engine->renderer(), filename, spdlog::get("idea"));
    engine->addToQueue(obj);
    return obj;
}

Object::Object(const std::string& id, ResourceManager* manager, SDL_Renderer* renderer, const std::string& filename, std::shared_ptr<spdlog::logger> log)
    : _loaded(false)
    , _id(id)
    , _manager(manager)
    , _renderer(renderer)
    , _log(log)
{
    _attached = true;
    _log->info("Creating object with id: {0} from {1}", _id, filename);
    _filename = filename;
    _x = -999;
    _y = -999;
}

Object::~Object()
{
}

bool Object::Load()
{
    _texture = _manager->texture(_filename);
    if (_texture == nullptr) return false;
    _loaded = true;
    _log->info("Object {0} loaded", _id);
    return true;
}

void Object::setPosition(int x, int y)
{
    _x = x;
    _y = y;
}

void Object::Render(Camera* camera)
{
    if (_texture == nullptr || !_loaded) return;
    SDL_Rect dst;
    if (_attached) {
        dst = { _x + camera->x(), _y + camera->y(), _texture->width(), _texture->height() };
    } else {
        dst = { _x, _y, _texture->width(), _texture->height() };
    }
    SDL_RenderCopy(_renderer, _texture->get(), NULL, &dst);
    return;
}

const std::string& Object::id() const
{
    return _id;
}

void Object::attach()
{
    _attached = true;
}

void Object::detach()
{
    _attached = false;
}

bool Object::loaded()
{
    return _loaded;
}
}
