#pragma once
#include <iostream>
#include <string>
#include <SDL.h>

namespace Snake {
  class Utils {
    public:
      static void logSDLError(std::ostream &os, const std::string &msg) {
        os << msg << " Error: " << SDL_GetError() << std::endl;
      }
      static void debug(const std::string &msg) {
        bool shouldDebug = false;
        char* debugEnv = std::getenv("DEBUG");
        if (debugEnv != NULL && strcmp(debugEnv, "1") == 0) {
          shouldDebug = true;
        }

        if (shouldDebug) {
          std::cout << "Debug: " << msg << std::endl;
        }
      }
  };
}
