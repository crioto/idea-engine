#ifndef __IDEA_ENGINE_LEVEL_H__
#define __IDEA_ENGINE_LEVEL_H__

#include <iostream>

#include "Command.hpp"

namespace IdeaEngine
{
    class Level : public Command
    {
        public:
        Level(const std::string& seed);
        ~Level();
        bool handleCommand(const std::string& command);
        std::string getSeed();
        void build();
        double perlin(double x, double y, double z);
        private:
        std::string _seed;
    };
}

#endif
