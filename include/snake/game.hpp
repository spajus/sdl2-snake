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

      bool running() { return m_bRunning; }

    private:

      SDL_Window* m_pWindow = 0;
      SDL_Renderer* m_pRenderer = 0;
      Tilemap* m_pTilemap = 0;

      int screenW = 0;
      int screenH = 0;

      bool m_bRunning;
  };
};
