#ifndef __IDEA_ENGINE_SIMULATION_H__
#define __IDEA_ENGINE_SIMULATION_H__

#include "Command.hpp"

namespace IdeaEngine
{
    typedef enum {
        SIM_INIT,
        SIM_RUNNING,
        SIM_SHUTDOWN
    } SimulationState;

    class Simulation : public Command
    {
        public:
            Simulation();
            ~Simulation();
            bool handleCommand(const std::string& command);
            SimulationState getState();
            void setState(SimulationState state);
        private:
            SimulationState _state;
    };
}

#endif
