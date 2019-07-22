#ifndef __EVENTS_HPP__
#define __EVENTS_HPP__

#include "Event.hpp"
#include "Simulation.hpp"
#include "Scene.hpp"

class GameEvent : public IdeaEngine::EventBase {
 public:
  GameEvent(const std::string& id, IdeaEngine::Engine* eng);
  void handleKeyUp(SDL_Keycode key);
  void handleMouseUp(Uint8 button, Uint32 state, Sint32 x, Sint32 y, int clicks);
  void setGUIScene(IdeaEngine::Scene* scene);

 private:
  IdeaEngine::Engine* _engine;
  IdeaEngine::Simulation* _sim;
  IdeaEngine::Scene* _uiScene;
};

#endif
