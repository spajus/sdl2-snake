#include "snake/audio.hpp"

void Snake::Audio::init() {
   if (Mix_OpenAudio(48000, MIX_DEFAULT_FORMAT, 2, 4096) >= 0) {
     m_pMusic = Mix_LoadMUS("../resources/audio/snake.ogg");
     Mix_PlayMusic(m_pMusic, -1);
  }
}

void Snake::Audio::clean() {
  Mix_FreeMusic(m_pMusic);
  Mix_Quit();
}
