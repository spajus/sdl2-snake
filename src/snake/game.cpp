#include "snake/game.hpp"

void Snake::Game::init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
    window = SDL_CreateWindow("SDL Snake",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640, 480,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window != 0) {
      renderer = SDL_CreateRenderer(window, -1, 0);
    }
  } else {
    Snake::Utils::logSDLError(std::cout, "Failed initializing SDL");
    is_running = false;
  }

  tilemap = new Snake::Tilemap();
  tilemap->init(renderer, 32, 32);
  tilemap->addTile("../resources/images/grass.png", "grass");

  is_running = true;
}

void Snake::Game::render() {
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  tilemap->fillWith("grass", 0, 0, screen_w, screen_h);
  SDL_RenderPresent(renderer);
}

void Snake::Game::handleEvents() {
  SDL_Event event;
  if (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_QUIT:
        is_running = false;
        break;
      case SDL_WINDOWEVENT:
        switch (event.window.event) {
          case SDL_WINDOWEVENT_SHOWN:
          case SDL_WINDOWEVENT_SIZE_CHANGED:
            SDL_GetWindowSize(window, &screen_w, &screen_h);
            break;
        }
        break;
      default:
        Utils::debug(std::to_string(event.type));
        break;
    }
  }
}

void Snake::Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}
