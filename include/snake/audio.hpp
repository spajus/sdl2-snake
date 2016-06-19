#pragma once
#include "utils.hpp"
#include "sdl_includes.hpp"
namespace Snake {
  class Audio {
    public:
      Audio() {}
      ~Audio() {}

    void init();
    void clean();

    private:
     Mix_Music* music = nullptr;
  };
};
