#include "snake/sdl_includes.hpp"
#include "snake/game.hpp"
#include "snake/audio.hpp"
#include "snake/utils.hpp"

Snake::Game* game = 0;
Snake::Audio* audio = 0;

int main(int argc, char* argv[]) {
  game = new Snake::Game();
  audio = new Snake::Audio();
  game->init();
  audio->init();

  while (game->isRunning()) {
    game->handleEvents();
    game->update();
    game->render();
    SDL_Delay(10);
  }

  audio->clean();
  game->clean();

  return 0;
}
