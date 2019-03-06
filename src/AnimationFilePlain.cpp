#include "AnimationFilePlain.hpp"

#include <iostream>

namespace IdeaEngine 
{
    AnimationFilePlain::AnimationFilePlain(const std::string& filename) : AnimationFileBase(filename)
    {

    }

    AnimationFilePlain::~AnimationFilePlain()
    {

    }

    std::vector<Frame> AnimationFilePlain::unmarshal(const std::string& data)
    {
        std::vector<Frame> frames;


        
        return frames;
    }

    std::string AnimationFilePlain::marshal(std::vector<Frame> data)
    {
        std::stringstream buffer;
        buffer << data.size() << " ";
        for (auto &it : data)
        {
            buffer << it.index << " ";
            buffer << it.x << " ";
            buffer << it.y << " ";
            buffer << it.w << " ";
            buffer << it.h << " ";
        }
        return buffer.str();
    }
}
