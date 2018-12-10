#include "Command.hpp"

namespace IdeaEngine
{

    bool Command::handleCommand(const std::string& command)
    {
        return false;
    }

    const std::string& Command::output() const {
        return _output;
    }

}
