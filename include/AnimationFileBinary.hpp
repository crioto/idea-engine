#ifndef __ANIMATION_FILE_BINARY_HPP__
#define __ANIMATION_FILE_BINARY_HPP__

#include "AnimationFileBase.hpp"

namespace IdeaEngine 
{
    class AnimationFileBinary : public AnimationFileBase 
    {
        public:
        AnimationFileBinary(const std::string& filename);
        ~AnimationFileBinary();
        std::vector<Frame> unmarshal(char** data);
        char** marshal(std::vector<Frame> data);

        template<typename T>
        char* encode(T value)
        {
            return (char*) &value;
            // char output[8];
            // int i = 0;
            // do
            // {
            //     unsigned char c = (unsigned char) (value & 0x7F);
            //     value >>= 7;
            //     if (value) c |= 0x80;
            //     output[i] = c;
            //     i++;
            // } while (value);
            // return output;
        }
    };
}

#endif