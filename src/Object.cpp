#include "Object.hpp"

namespace Engine {

    Object* NewObject(SDL_Renderer *renderer, const std::string& filename)
    {
        Object* obj = new Object(renderer, filename);
        if (!obj->Load())
        {
            delete obj;
            return nullptr;
        }
        return obj;
    }

    Object::Object(SDL_Renderer* renderer, const std::string& filename) : _renderer(renderer)
    {
        _filename = filename;
        _x = -999;
        _y = -999;
    }

    Object::~Object()
    {

    }

    bool Object::Load()
    {
        if (_renderer == NULL) 
        {
            return false;
        }
        SDL_Surface* img = IMG_Load(_filename.c_str());
        if (img == NULL) 
        {
            std::cout << "Failed to load texture from file: " << _filename << ": " << IMG_GetError() << std::endl;
            return false;
        }

        if((_texture = SDL_CreateTextureFromSurface(_renderer, img)) == NULL) {
            std::cout << "Failed to create texture from file " << _filename << ": " << IMG_GetError() << std::endl;
            return false;
        }

        SDL_QueryTexture(_texture, NULL, NULL, &_width, &_height);
        SDL_FreeSurface(img);
        return true;
    }

    void Object::setPosition(int x, int y) 
    {
        _x = x;
        _y = y;
    }

    void Object::Render()
    {
        SDL_Rect dst = {_x, _y, _width, _height};
        SDL_RenderCopy(_renderer, _texture, NULL, &dst);
    }
}
