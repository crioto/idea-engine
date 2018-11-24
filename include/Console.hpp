#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <iostream>
#include <string>
#include <vector>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
#include "SDL.h"
#include "SDL_ttf.h"
#else
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#endif

#include "EventBase.hpp"
#include "ConsoleCommand.hpp"

namespace Engine {
class Console : public EventBase {
public:
    Console(SDL_Renderer* renderer);
    virtual ~Console();
    void activate();
    void deactivate();
    void toggle();
    void handleText(const std::string& text);
    void updateInput();
    void Render();
    void subscribe(ConsoleCommand* commandClass);
    void process(const std::string& command);
    // events
    void handleKeyUp(SDL_Keycode key);
    void handleKeyDown(SDL_Keycode key);
    void handleText(char* characters);
private:
    bool _isActive;
    SDL_Renderer* _renderer;
    SDL_Texture* _inputTexture;
    SDL_Texture* _historyTexture;
    SDL_Rect* _rect;
    TTF_Font* _font;
    std::string _buffer;
    std::vector<std::string> _history;
    std::vector<ConsoleCommand*> _commands;
};
}

#endif
