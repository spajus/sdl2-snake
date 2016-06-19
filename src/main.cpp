#include "snake/sdl_includes.hpp"
#include "snake/game.hpp"
#include "snake/audio.hpp"
#include "snake/utils.hpp"

Snake::Game* g_game = 0;
Snake::Audio* g_audio = 0;

int main(int argc, char* argv[]) {
  g_game = new Snake::Game();
  g_audio = new Snake::Audio();
  g_game->init();
  g_audio->init();

  while (g_game->running()) {
    g_game->handleEvents();
    g_game->update();
    g_game->render();
  }

  g_audio->clean();
  g_game->clean();

  return 0;
}
