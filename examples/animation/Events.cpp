#include "Events.hpp"
#include "Engine.hpp"

GameEvent::GameEvent(const std::string& id, IdeaEngine::Engine* engine) : IdeaEngine::EventBase(id, engine)
{
    _sim = engine->simulation();
}

void GameEvent::handleKeyUp(SDL_Keycode key) 
{
    if (key == SDLK_ESCAPE) {
        _sim->setState(IdeaEngine::SimulationState::SIM_SHUTDOWN);
    }
}
