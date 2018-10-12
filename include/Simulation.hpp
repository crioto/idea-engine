#ifndef __SIMULATION_H__
#define __SIMULATION_H__

#include "ConsoleCommand.hpp"

typedef enum {
    SIM_INIT,
    SIM_RUNNING,
    SIM_SHUTDOWN
} SimulationState;

namespace Engine
{
    class Simulation : public ConsoleCommand
    {
        public:
        Simulation();
        ~Simulation();
        bool handleConsoleCommand(const std::string& command);
        SimulationState getState();
        private:
        SimulationState _state;
    };
}

#endif