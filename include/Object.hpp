#ifndef __IDEA_ENGINE_OBJECT_H__
#define __IDEA_ENGINE_OBJECT_H__

#include <iostream>
#include <string>

#include "spdlog/spdlog.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
#include <SDL.h>
#include <SDL_image.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

#include "Camera.hpp"
#include "ResourceManager.hpp"

namespace IdeaEngine {

class Engine;

class Object {
public:
    Object(const std::string& id, ResourceManager* manager, SDL_Renderer* renderer, const std::string& filename, std::shared_ptr<spdlog::logger> log);
    ~Object();
    virtual bool load();
    virtual void render(Camera* camera);

    void attach();
    void detach();
    bool loaded();
    void hide();
    void show();

    // setters
    void setX(int x);
    void setY(int y);
    void setWidth(int w);
    void setHeight(int h);
    void setPosition(int x, int y);

    // getters
    int x();
    int y();
    int width();
    int height();
    const std::string& id() const;

protected:
    std::string _id; // Object ID. Not guarantted to be unique within any scope
    std::string _filename; // Filename of the object if any
    SDL_Renderer* _renderer; // Renderer that is passed to underlying elements
    Texture* _texture;
    int _x;
    int _y;
    int _w;
    int _h;
    
    std::shared_ptr<spdlog::logger> _log;
    bool _hidden; // hidden objects are not rendered
    bool _attached; // whether or not this object attached to camera
    bool _loaded; // whether or not this object was loaded
    ResourceManager* _manager; // resource manager used to load objects
};

Object* NewObject(const std::string& id, Engine* engine, const std::string& filename);
Object* NewObjectInQueue(const std::string& id, Engine* engine, const std::string& filename);
};

#endif
