#ifndef __RESOURCES_H__
#define __RESOURCES_H__

#include <map>
#include <string>

#include "Texture.hpp"

namespace Engine {

    typedef std::map<std::string, Texture*> TextureList;

    class Resources 
    {
        public:
        Resources();
        ~Resources();

    };
}

#endif