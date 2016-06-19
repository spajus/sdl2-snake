#pragma once
#include "snake/game_object.hpp"
namespace Snake {
  class Player : public GameObject {
    public:
      void load(int x, int y);

  };
}
