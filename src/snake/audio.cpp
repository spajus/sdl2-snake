#include "snake/audio.hpp"

void Snake::Audio::init() {
   if (Mix_OpenAudio(48000, MIX_DEFAULT_FORMAT, 2, 4096) >= 0) {
     music = Mix_LoadMUS("../resources/audio/snake.ogg");
     Mix_PlayMusic(music, -1);
  }
}

void Snake::Audio::clean() {
  Mix_FreeMusic(music);
  Mix_Quit();
}
