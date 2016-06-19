#pragma once
#include "snake/game_object.hpp"
#include "snake/direction.hpp"

namespace Snake {
  class Player : public GameObject {
    public:
      void load(int x, int y);
      void update();
    private:
      Direction direction = down;
      int speed = 32;
  };
}
