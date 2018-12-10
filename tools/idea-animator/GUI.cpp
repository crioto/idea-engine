#include "GUI.hpp"

GUI::GUI(IdeaEngine::Engine* engine) :
  _engine(engine)
{
  _scene = IdeaEngine::NewScene("gui", engine->renderer());
}

GUI::~GUI()
{

}

void GUI::create()
{
  
}

std::shared_ptr<IdeaEngine::Scene> GUI::get()
{
  return _scene;
}