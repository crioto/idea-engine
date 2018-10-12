#include "Event.hpp"

namespace Engine {
    Event::Event()
    {
    }

    Event::~Event()
    {
    }

    void Event::process(SDL_Event* event)
    {
        switch (event->type) {
            case SDL_KEYUP:
            keyUp(event->key.keysym.sym);
            break;
            case SDL_KEYDOWN:
            keyDown(event->key.keysym.sym);
            break;
            case SDL_TEXTINPUT:
            keyText(event->text.text);
            break;
        }
        // switch (event->type) {
        //     case SDL_QUIT:
        //         _running = false;
        //         break;
        //     case SDL_KEYDOWN:
        //         if (event.key.keysym.sym == SDLK_q) {
        //             console->activate();
        //         }
        //         break;
        //     case SDL_TEXTINPUT:
        //         console->handleText(std::string(event.text.text));
        //         break;
        // };
    }

    void Event::subscribe(EventBase* ev)
    {
        _events.push_back(ev);
    }

    void Event::keyUp(SDL_Keycode key)
    {
        for (auto it = _events.begin(); it != _events.end(); it++) {
            (*it)->handleKeyUp(key);
        }
    }

    void Event::keyDown(SDL_Keycode key)
    {
        for (auto it = _events.begin(); it != _events.end(); it++) {
            (*it)->handleKeyDown(key);
        }
    }

    void Event::keyText(char* characters)
    {
        for (auto it = _events.begin(); it != _events.end(); it++) {
            (*it)->handleText(characters); 
        }
    }
}
