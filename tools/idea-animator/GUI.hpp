#ifndef __GUI_HPP__
#define __GUI_HPP__

#include "Engine.hpp"
#include "Scene.hpp"
#include "Object.hpp"

class GUI {
  public:
    GUI(IdeaEngine::Engine* engine);
    ~GUI();

    void create();

    std::shared_ptr<IdeaEngine::Scene> get();

  private:
    IdeaEngine::Engine* _engine;
    std::shared_ptr<IdeaEngine::Scene> _scene;
};  

#endif