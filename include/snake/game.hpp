#pragma once
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "snake/utils.hpp"
#include "snake/tilemap.hpp"
namespace Snake {
  class Game {
    public:
      Game() {}
      ~Game() {}

      void init();
      void render();

      void update() { }

      void handleEvents();
      void clean();

      bool isRunning() { return is_running; }

    private:

      SDL_Window* window = nullptr;
      SDL_Renderer* renderer = nullptr;
      Tilemap* tilemap = nullptr;

      int screen_w = 0;
      int screen_h = 0;

      bool is_running;
  };
};
