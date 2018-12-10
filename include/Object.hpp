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
        Object(const std::string& id, ResourceManager* manager, SDL_Renderer *renderer, const std::string& filename, std::shared_ptr<spdlog::logger> log);
        ~Object();
        bool Load();
        void setPosition(int x, int y);
        void Render(Camera *camera);
        const std::string& id() const;
        void attach();
        void detach();
        bool loaded();
        protected:
        std::string _filename;
        SDL_Renderer *_renderer;
        Texture *_texture;
        int _x;
        int _y;
        std::string _id;
        std::shared_ptr<spdlog::logger> _log;
        bool _attached; // whether or not this object attached to camera
        bool _loaded; // whether or not this object was loaded
        ResourceManager* _manager;
    };

    Object* NewObject(const std::string& id, Engine* engine, const std::string& filename);
    Object* NewObjectInQueue(const std::string& id, Engine* engine, const std::string& filename);
};

#endif
