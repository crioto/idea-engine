#ifndef __IDEA_ENGINE_STRINGS_UTIL_HPP__
#define __IDEA_ENGINE_STRINGS_UTIL_HPP__

#include <vector>
#include <string>

namespace IdeaEngine 
{
    class StringsUtil
    {
        public:
        enum Options 
        {
            SPLIT_IGNORE_EMPTY = 1,
            SPLIT_TRIM = 2
        };
        
        // split string into parts using specified separator
        static std::vector<std::string> Split(const std::string& str, const std::string& separator, int options = 0);
        static void Trim(std::string& str);
    };
}

#endif