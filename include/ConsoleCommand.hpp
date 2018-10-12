#ifndef __CONSOLE_COMMAND_H__
#define __CONSOLE_COMMAND_H__

#include <string>

namespace Engine
{
    class ConsoleCommand 
    {
        public:
        virtual bool handleConsoleCommand(const std::string& command);
    };
}

#endif