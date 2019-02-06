#include "AnimationFileBase.hpp"

namespace IdeaEngine {

    AnimationFileBase::AnimationFileBase(const std::string& filename) : _filename(std::move(filename))
    {

    }

    AnimationFileBase::~AnimationFileBase()
    {

    }

    const std::string& AnimationFileBase::filename() const 
    {
        return _filename;
    }

    std::vector<Frame> AnimationFileBase::get()
    {
        return _frames;
    }

    void AnimationFileBase::set(std::vector<Frame> frames)
    {
        _frames = frames;
    }

    std::vector<Frame> AnimationFileBase::load()
    {
        return _frames;
    }

    void AnimationFileBase::save()
    {
        
    }

}