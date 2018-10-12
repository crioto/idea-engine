#ifndef __EVENT_BASE_H__
#define __EVENT_BASE_H__

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
#include "SDL.h"
#else
#include "SDL2/SDL.h"
#endif

namespace Engine
{
    class EventBase 
    {
        public:
        virtual void handleKeyUp(SDL_Keycode key);
        virtual void handleKeyDown(SDL_Keycode key);
        virtual void handleText(char* characters);
    };
}

#endif