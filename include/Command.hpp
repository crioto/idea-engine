#ifndef __IDEA_ENGINE_CONSOLE_COMMAND_H__
#define __IDEA_ENGINE_CONSOLE_COMMAND_H__

#include <string>

namespace IdeaEngine
{
    class Command 
    {
        public:
        virtual bool handleCommand(const std::string& command);
        virtual const std::string& output() const;
        protected:
        std::string _output;
    };
}

#endif
