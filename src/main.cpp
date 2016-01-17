#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "sdl_utils.hpp"

int main(int argc, char* argv[]) {
  std::cout << "This works" << std::endl;
  logSDLError(std::cout, "iitest");
  return 0;
}
