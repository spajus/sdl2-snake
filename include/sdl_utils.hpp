# pragma once
#include <iostream>
#include <string>
#include <SDL.h>

void logSDLError(std::ostream &os, const std::string &msg) {
  os << msg << " Error: " << SDL_GetError() << std::endl;
}
