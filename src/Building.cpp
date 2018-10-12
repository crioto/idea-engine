#include "Building.hpp"

namespace Engine
{
    Building::Building(SDL_Renderer* renderer, int seed, int x, int y)
    {
        _seed = seed;
        _x = x;
        _y = y;
        _renderer = renderer;
    }

    Building::~Building()
    {

    }

    void Building::generate()
    {
        int number = _seed + _x + _y;
        int bn, bw;
        srand(number);
        bn = (rand() % 6) + 3;
        bw = (rand() % 6) + 3;

        bool doorHasSpawn = false;
        bool doorWest = false;
        int doorMax = bn;

        if (rand() * 1000 > 500) {
            doorWest = true;
            doorMax = bw;
        }

        int doorPos = 0;
        int doorIt = 0;
        while (doorPos == 0)
        {
            if (rand() * 1000 > 800) {
                doorPos = doorIt;
            }
            doorIt++;
            if (doorPos == doorMax) {
                doorPos = 0;
            }
        }

        for (int i = 0; i < bn; i++)
        {
            Object* w = new Object(_renderer, "../assets/wall2_n.png");
            w->Load();
            w->setPosition(_x + (32 * i), _y - (16 * i));
            _objects.push_back(w);
            if (!doorWest) 
            {
                if (i == doorPos)
                {
                    Object *d = new Object(_renderer, "../assets/door_n.png");
                    d->Load();
                    d->setPosition(_x + (32 * i), _y - (16 * i));
                    _objects.push_back(d);
                    continue;
                }
            }

            if (rand() * 1000 > 800) 
            {
                Object *window = new Object(_renderer, "../assets/window_n.png");
                window->Load();
                window->setPosition(_x + (32 * i), _y - (16 * i));
                _objects.push_back(window);
            }
        }

        for (int i = 0; i < bw - 1; i++)
        {
            Object* w = new Object(_renderer, "../assets/wall_w.png");
            w->Load();
            w->setPosition(_x - (32 * i + 32), _y - (16 * i));
            _objects.push_back(w);
            //scene->addObject(w); 
            if (doorWest) 
            {
                if (i == doorPos)
                {
                    Object *d = new Object(_renderer, "../assets/door_w.png");
                    d->Load();
                    d->setPosition(_x - (32 * i + 32), _y - (16 * i));
                    _objects.push_back(d);
                    continue;
                }
            }

            if (rand() * 1000 > 800) 
            {
                Object *window = new Object(_renderer, "../assets/window_w.png");
                window->Load();
                window->setPosition(_x - (32 * i + 32), _y - (16 * i));
                _objects.push_back(window);
            }
        }
    }

    void Building::render()
    {
        for (auto it = _objects.begin(); it != _objects.end(); it++)
        {
            (*it)->Render();
        }
    }
}