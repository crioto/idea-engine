#include "EventBase.hpp"

namespace IdeaEngine
{
    EventBase::EventBase(const std::string& id) : _id(id)
    {

    }

    const std::string& EventBase::id() const
    {
        return _id;
    }

    void EventBase::handleKeyDown(SDL_Keycode key)
    {

    }

    void EventBase::handleKeyUp(SDL_Keycode key)
    {
 
    }

    void EventBase::handleText(char* characters)
    {
        
    }

    void EventBase::handleMouseMove(Uint32 state, Sint32 x, Sint32 y, Sint32 xrel, Sint32 yrel)
    {
        
    }

    bool EventBase::operator==(const EventBase& eb) const
    {
        return (_id == eb.id());
    }
}
