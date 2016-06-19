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
        bool should_debug = false;
        char* debug_env = std::getenv("DEBUG");
        if (debug_env != NULL && strcmp(debug_env, "1") == 0) {
          should_debug = true;
        }

        if (should_debug) {
          std::cout << "Debug: " << msg << std::endl;
        }
      }
  };
}
