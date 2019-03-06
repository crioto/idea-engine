#include "GUI.hpp"

GUI::GUI(IdeaEngine::Engine* engine) :
  _engine(engine)
{
  _scene = IdeaEngine::NewScene("gui");
}

GUI::~GUI()
{

}

void GUI::create()
{
  //NewObject();
  SDL_Color color{ 200, 200, 200, 255 };
  IdeaEngine::Rectangle *topmenu = new IdeaEngine::Rectangle("topmenu", _engine->renderer(), 0, 0, _engine->getWindowWidth(), 20, color, _engine->log());
  _scene->addObject(topmenu);

  // Create menu elements
  IdeaEngine::Text *open = new IdeaEngine::Text("Open", _engine->manager(), _engine->renderer(), "assets/fonts/Everyday.ttf", _engine->log());
  open->load();
  open->setColor({22, 22, 22, 255});
  open->update();
  open->setPosition(10, 5);
  _scene->addObject(open);

  IdeaEngine::Text *save = new IdeaEngine::Text("Save", _engine->manager(), _engine->renderer(), "assets/fonts/Everyday.ttf", _engine->log());
  save->load();
  save->setColor({22, 22, 22, 255});
  save->update();
  save->setPosition(open->x() + open->width() + 10, 5);
  _scene->addObject(save);
}

std::shared_ptr<IdeaEngine::Scene> GUI::get()
{
  return _scene;
}