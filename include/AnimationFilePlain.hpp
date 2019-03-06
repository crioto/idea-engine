#ifndef __ANIMATION_FILE_Plain_HPP__
#define __ANIMATION_FILE_Plain_HPP__

#include <sstream>

#include "AnimationFileBase.hpp"

namespace IdeaEngine 
{
    class AnimationFilePlain : public AnimationFileBase 
    {
        public:
        AnimationFilePlain(const std::string& filename);
        ~AnimationFilePlain();
        std::vector<Frame> unmarshal(const std::string& data);
        std::string marshal(std::vector<Frame> data);
    };
}

#endif