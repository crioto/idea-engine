#ifndef __IDEA_ENGINE_EVENT_BASE_H__
#define __IDEA_ENGINE_EVENT_BASE_H__

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

#include <string>

namespace IdeaEngine
{
    class Engine;

    class EventBase 
    {
        public:
        EventBase(const std::string& id, Engine *engine);
        virtual const std::string& id() const;
        virtual void handleKeyUp(SDL_Keycode key);
        virtual void handleKeyDown(SDL_Keycode key);
        virtual void handleText(char* characters);
        virtual void handleMouseMove(Uint32 state, Sint32 x, Sint32 y, Sint32 xrel, Sint32 yrel);
        virtual void handleMouseDown(Uint8 button, Uint32 state, Sint32 x, Sint32 y, int clicks);
        virtual void handleMouseUp(Uint8 button, Uint32 state, Sint32 x, Sint32 y, int clicks);
        virtual bool operator==(const EventBase& eb) const;
        protected:
        std::string _id;
        Engine* _engine;
    };
}

#endif
