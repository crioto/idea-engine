#include "Events.hpp"

GameEvent::GameEvent(const std::string& id, IdeaEngine::Simulation* sim) : IdeaEngine::EventBase(id)
{
    _sim = sim;
}

void GameEvent::handleKeyUp(SDL_Keycode key) 
{
    if (key == SDLK_ESCAPE) {
        _sim->setState(IdeaEngine::SimulationState::SIM_SHUTDOWN);
    }
}
