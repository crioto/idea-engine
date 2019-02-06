#ifndef __ANIMATION_FILE_BASE_HPP__
#define __ANIMATION_FILE_BASE_HPP__

#include <string>
#include <vector>

namespace IdeaEngine {

  struct Frame
  {
    uint8_t index;
    uint16_t x;
    uint16_t y;
    uint16_t w;
    uint16_t h;
  };

    class AnimationFileBase {
        public:
        AnimationFileBase(const std::string& filename);
        ~AnimationFileBase();
        const std::string& filename() const;
        virtual std::vector<Frame> load();
        virtual void save();
        virtual std::vector<Frame> unmarshal(char** data) = 0;
        virtual char** marshal(std::vector<Frame> data) = 0;
        std::vector<Frame> get();
        void set(std::vector<Frame> frames);
        protected:
        std::string _filename;
        std::vector<Frame> _frames;
    };
}

#endif