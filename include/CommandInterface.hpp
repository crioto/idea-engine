#ifndef __IDEA_ENGINE_CONSOLE_H__
#define __IDEA_ENGINE_CONSOLE_H__

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "spdlog/spdlog.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
#include "SDL.h"
#include "SDL_ttf.h"
#else
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#endif

#include "Command.hpp"
#include "EventBase.hpp"
#include "Object.hpp"

namespace IdeaEngine {

class Engine;

class CommandInterface : public EventBase {
public:
    CommandInterface(const std::string& id, Engine* engine);
    virtual ~CommandInterface();
    void activate();
    void deactivate();
    void toggle();
    void handleText(const std::string& text);
    void updateInput();
    void Render();
    void subscribe(Command* commandClass);
    void process(const std::string& command);
    // configuration
    void setWidth(int w);
    void setHeight(int h);
    // events
    void handleKeyUp(SDL_Keycode key);
    void handleKeyDown(SDL_Keycode key);
    void handleText(char* characters);
protected:
    void updateHistory();
    // splitOutput will split string by newlines
    void splitOutput(const std::string& output);
private:
    bool _isActive;
    SDL_Renderer* _renderer;
    SDL_Texture* _inputTexture;
    std::vector<SDL_Texture*> _historyTexture;
    SDL_Rect* _rect;
    TTF_Font* _font;
    std::string _buffer;
    std::vector<std::string> _history; // Full history
    std::vector<std::string> _cmdHistory; // History of all executed commands
    std::vector<Command*> _commands;
    int _historyCursor = 0;
    std::shared_ptr<spdlog::logger> _log;
};
}

#endif
