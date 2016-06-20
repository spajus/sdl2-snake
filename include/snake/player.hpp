#pragma once
#include "snake/game_object.hpp"
#include "snake/direction.hpp"

namespace Snake {
  class Player : public GameObject {
    public:
      void load(int x, int y);
      void update();
      Direction direction = down;
    private:
      int speed = 128;
  };
}
