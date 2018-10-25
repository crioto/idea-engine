#include "Console.hpp"

namespace Engine {

Console::Console(SDL_Renderer* renderer)
    : _isActive(false)
    , _renderer(renderer)
{
    _rect = new SDL_Rect();
    _rect->h = 200;
    _rect->w = 600;
    _rect->x = 0;
    _rect->y = 0;


    _font = TTF_OpenFont("../assets/fonts/pixelsix.ttf", 16);
    if (_font == NULL) {
        std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
    }
}

Console::~Console()
{
    delete _rect;
}

void Console::activate()
{
    _isActive = true;
    updateInput();
    SDL_StartTextInput();
}

void Console::deactivate()
{
    _isActive = false;
    SDL_StopTextInput();
}

void Console::toggle()
{
    if (_isActive) {
        deactivate();
    } else {
        activate();
    }
}

void Console::handleText(const std::string& text)
{
    if (!_isActive) return;

    _buffer.append(text);
    updateInput();
}

void Console::updateInput()
{
    if (_renderer == NULL) return;
    if (_font == NULL) return;

    std::string buffer("");
    if (_buffer.length() == 0) 
    {
        buffer = " ";
    } 
    else 
    {
        buffer.append(_buffer);
    }
    SDL_Color color;
    color.r = 255;
    color.g = 255;
    color.b = 255;
    color.a = 255;
    auto inputSurface = TTF_RenderUTF8_Solid(_font, buffer.c_str(), color);
    if (inputSurface == NULL) {
        std::cout << "Failed to render text: " << TTF_GetError() << std::endl;
        return;
    }
    if((_inputTexture = SDL_CreateTextureFromSurface(_renderer, inputSurface)) == NULL) {
        std::cout << "Failed to create texture: " << SDL_GetError() << std::endl;
        return;
    }
    SDL_FreeSurface(inputSurface);
}

void Console::Render()
{
    if (!_isActive) return;
    if (_font == NULL) return;
    if (_inputTexture == NULL) return;

    SDL_SetRenderDrawColor(_renderer, 22, 22, 22, 200);
    SDL_RenderFillRect(_renderer, _rect);
    int w = 0;
    int h = 0;
    SDL_QueryTexture(_inputTexture, NULL, NULL, &w, &h);
    SDL_Rect dst = {5, 180, int(_buffer.length() * 13), 16};
    SDL_RenderCopy(_renderer, _inputTexture, NULL, &dst);
}

void Console::handleKeyDown(SDL_Keycode key)
{
    if (_isActive)
    {
        if (key == SDLK_RETURN) 
        {
            std::cout << "Processing command: " << _buffer << std::endl;
            process(_buffer);
            _buffer = std::string("");
        } 
        else if (key == SDLK_BACKSPACE && _buffer.length() > 0)
        {
            std::cout << "Backspace" << std::endl;
            _buffer = _buffer.substr(0, _buffer.length() - 1);
        } 
        else if (key == SDLK_BACKQUOTE) 
        {
            _buffer = std::string("");
            deactivate();
        }
        updateInput();
    } 
    else
    {
        if (key == SDLK_BACKQUOTE) 
        {
            activate();
        }
    }
}

void Console::handleKeyUp(SDL_Keycode key)
{
    
}

void Console::handleText(char* characters)
{
    if (!_isActive) return;
    if (std::string(characters) == std::string("`")) return;

    _buffer.append(std::string(characters));
    updateInput();
}

void Console::subscribe(ConsoleCommand* commandClass)
{
    _commands.push_back(commandClass);
}

void Console::process(const std::string& command)
{
    bool rc = false;
    for (auto it = _commands.begin(); it != _commands.end(); it++)
    {
        rc = (*it)->handleConsoleCommand(command);
        if (rc) return;
    }
    if (!rc)
    {
        _history.push_back("Command not found: "+command);
    }
}

}
