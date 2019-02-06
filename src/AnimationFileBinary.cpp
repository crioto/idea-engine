#include "AnimationFileBinary.hpp"

namespace IdeaEngine 
{
    AnimationFileBinary::AnimationFileBinary(const std::string& filename) : AnimationFileBase(filename)
    {

    }

    AnimationFileBinary::~AnimationFileBinary()
    {

    }

    std::vector<Frame> AnimationFileBinary::unmarshal(char** data)
    {

    }

    char** AnimationFileBinary::marshal(std::vector<Frame> data)
    {
        for (auto &it : data)
        {
            std::printf("Encoding index: %d ", it.index);
            auto res = encode<uint32_t>(it.index);
            std::printf("Result: %s\n", res);
        }
    }
}
