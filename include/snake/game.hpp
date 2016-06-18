#pragma once
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "utils.hpp"
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

      bool running() { return m_bRunning; }

    private:

      SDL_Window* m_pWindow = 0;
      SDL_Renderer* m_pRenderer = 0;

      bool m_bRunning;
  };
};