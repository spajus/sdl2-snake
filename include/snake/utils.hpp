#pragma once
#ifndef _SDL_UTILS_H
#define _SDL_UTILS_H
#include <iostream>
#include <string>
#include <SDL.h>

namespace Snake {
  class Utils {
    public:
      static void logSDLError(std::ostream &os, const std::string &msg) {
        os << msg << " Error: " << SDL_GetError() << std::endl;
      }
  };
}
#endif
