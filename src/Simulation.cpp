#include "Simulation.hpp"

namespace Engine
{
    Simulation::Simulation()
    {
        _state = SIM_INIT;
    }

    Simulation::~Simulation()
    {

    }

    bool Simulation::handleConsoleCommand(const std::string& command)
    {
        if (command == "quit")
        {
            _state = SIM_SHUTDOWN;
            return true;
        }
        return false;
    }

    SimulationState Simulation::getState()
    {
        return _state;
    }
}