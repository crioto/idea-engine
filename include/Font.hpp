#ifndef __FONT_HPP__
#define __FONT_HPP__

#include <string>

#include "spdlog/spdlog.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32)
#include "SDL.h"
#include "SDL_ttf.h"
#else
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#endif

namespace IdeaEngine {
  class Font 
  {
    public:
      Font(const std::string& path, int size, std::shared_ptr<spdlog::logger> log);
      ~Font();
      bool load();
      TTF_Font* get();
      int size();
    private:
      int _size;
      std::string _id;
      TTF_Font* _font;
      std::shared_ptr<spdlog::logger> _log;
  };
}

#endif