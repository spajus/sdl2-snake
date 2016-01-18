#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "game.cpp"

int main(int argc, char* argv[]) {
  Snake::Game game;
  game.init();
  return 0;
}
