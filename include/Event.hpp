#ifndef __EVENT_H__
#define __EVENT_H__

#include <iostream>
#include <vector>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif
#include "EventBase.hpp"


namespace Engine 
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
        private:
        EventSubscriptions _events;
    };
}

#endif
