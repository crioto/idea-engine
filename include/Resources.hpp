#ifndef __IDEA_ENGINE_RESOURCES_H__
#define __IDEA_ENGINE_RESOURCES_H__

#include <map>
#include <string>

#include "Texture.hpp"

namespace IdeaEngine {

    typedef std::map<std::string, Texture*> TextureList;

    class Resources 
    {
        public:
        Resources();
        ~Resources();

    };
}

#endif