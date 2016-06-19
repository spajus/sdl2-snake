#include "snake/game.hpp"

void Snake::Game::init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
    m_pWindow = SDL_CreateWindow("SDL Snake",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640, 480,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    if (m_pWindow != 0) {
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
    }
  } else {
    Snake::Utils::logSDLError(std::cout, "Failed initializing SDL");
    m_bRunning = false;
  }

  m_pTilemap = new Snake::Tilemap();
  m_pTilemap->init(m_pRenderer, 32, 32);
  m_pTilemap->addTile("../resources/images/grass.png", "grass");

  m_bRunning = true;
}

void Snake::Game::render() {
  SDL_RenderClear(m_pRenderer);
  SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);

  int ww, wh = 0;
  SDL_GetWindowSize(m_pWindow, &ww, &wh);
  m_pTilemap->fillWith("grass", 0, 0, ww, wh);
  SDL_RenderPresent(m_pRenderer);
}

void Snake::Game::handleEvents() {
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

void Snake::Game::clean() {
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}
