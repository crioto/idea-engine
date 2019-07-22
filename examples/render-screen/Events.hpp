#ifndef __EVENTS_HPP__
#define __EVENTS_HPP__

#include "Event.hpp"
#include "Simulation.hpp"

class GameEvent : public IdeaEngine::EventBase {
    public:
        GameEvent(const std::string& id, IdeaEngine::Engine *engine);
        void handleKeyUp(SDL_Keycode key);
    private:
        IdeaEngine::Simulation* _sim;
};

#endif
