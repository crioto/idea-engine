#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <iostream>

#include "ConsoleCommand.hpp"

namespace Engine
{
    class Level : public ConsoleCommand
    {
        public:
        Level(const std::string& seed);
        ~Level();
        bool handleConsoleCommand(const std::string& command);
        std::string getSeed();
        void build();
        double perlin(double x, double y, double z);
        private:
        std::string _seed;
    };
}

#endif