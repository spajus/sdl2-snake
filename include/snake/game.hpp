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

      SDL_Window* m_pWindow = nullptr;
      SDL_Renderer* m_pRenderer = nullptr;
      Tilemap* m_pTilemap = nullptr;

      int screenW = 0;
      int screenH = 0;

      bool m_bRunning;
  };
};
