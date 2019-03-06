#ifndef __IDEA_ENGINE_EVENT_H__
#define __IDEA_ENGINE_EVENT_H__

#include <iostream>
#include <vector>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif
#include "EventBase.hpp"


namespace IdeaEngine 
{
    typedef std::vector<EventBase*> EventSubscriptions;

    class Event
    {
        public:
        Event();
        ~Event();
        void process(SDL_Event* event);
        void subscribe(EventBase* eb);
        void keyUp(SDL_Keycode key);
        void keyDown(SDL_Keycode key);
        void keyText(char* characters);
        void mouseMotion(Uint32 state, Sint32 x, Sint32 y, Sint32 xrel, Sint32 yrel);
        void mouseDown(Uint8 button, Uint32 state, Sint32 x, Sint32 y, int clicks);
        void mouseUp(Uint8 button, Uint32 state, Sint32 x, Sint32 y, int clicks);
        private:
        EventSubscriptions _events;
    };
}

#endif
