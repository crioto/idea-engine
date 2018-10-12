#include "Level.hpp"

namespace Engine
{
    Level::Level(const std::string& seed) : _seed(seed)
    {

    }

    Level::~Level()
    {

    }

    bool Level::handleConsoleCommand(const std::string& command)
    {
        
        return false;
    }

    std::string Level::getSeed()
    {
        return _seed;
    }

    void Level::build()
    {

    }

    double Level::perlin(double x, double y, double z)
    {
		return 0.0;
    }

}