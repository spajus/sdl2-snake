#pragma once
#include <iostream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "sdl_utils.hpp"

class Game {
  public:
    Game() {}
    ~Game() {}

    void init() {
      if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
        m_pWindow = SDL_CreateWindow("SDL Snake",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            640, 480, SDL_WINDOW_SHOWN);
        if (m_pWindow != 0) {
          m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
        }
      } else {
        logSDLError(std::cout, "Failed initializing SDL");
        m_bRunning = false;
      }
      m_bRunning = true;
    }

    void render() {
      SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
      SDL_RenderClear(m_pRenderer);
      SDL_RenderPresent(m_pRenderer);
    }

    void update() {
    }

    void handleEvents() {
      SDL_Event event;
      if (SDL_PollEvent(&event)) {
        switch (event.type) {
          case SDL_QUIT:
            m_bRunning = false;
            break;
          default:
            break;
        }
      }
    }

    void clean() {
      SDL_DestroyWindow(m_pWindow);
      SDL_DestroyRenderer(m_pRenderer);
      SDL_Quit();
    }

    bool running() { return m_bRunning; }

  private:

    SDL_Window* m_pWindow = 0;
    SDL_Renderer* m_pRenderer = 0;

    bool m_bRunning;
};
