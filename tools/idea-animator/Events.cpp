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

void GameEvent::handleMouseUp(Uint8 button, Uint32 state, Sint32 x, Sint32 y, int clicks)
{
    if (_uiScene == nullptr) return;

    auto objects = _uiScene->findObjects(x, y);
    for ( auto obj : objects ) {
        //if (obj->)
    }
}

void GameEvent::setGUIScene(IdeaEngine::Scene* scene)
{
    _uiScene = scene;
}
