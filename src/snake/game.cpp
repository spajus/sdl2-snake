#include "snake/game.hpp"
#include "snake/player.hpp"
#include "snake/tilemap.hpp"

void Snake::Game::init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
    window = SDL_CreateWindow("SDL Snake",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        640, 480,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window != 0) {
      renderer = SDL_CreateRenderer(window, -1,
          SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    }
  } else {
    Snake::Utils::logSDLError(std::cout, "Failed initializing SDL");
    is_running = false;
  }

  Tilemap* tilemap = Tilemap::instance();
  tilemap->init(renderer, 32, 32);
  tilemap->addTile("../resources/images/grass.png", "grass");
  tilemap->addTile("../resources/images/snake_head.png", "snake_head");
  tilemap->addTile("../resources/images/snake_body.png", "snake_body");

  player = new Player();
  player->load(100, 100);

  is_running = true;
}

void Snake::Game::render() {
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  Tilemap::instance()->fillWith("grass", 0, 0, screen_w, screen_h);
  player->draw();
  SDL_RenderPresent(renderer);
}

void Snake::Game::update() {
  player->update();
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
