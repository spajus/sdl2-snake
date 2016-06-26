#pragma once
#include "snake/game_object.hpp"
#include "snake/direction.hpp"
#include "snake/tail_node.hpp"

namespace Snake {
  class Player : public GameObject {
    public:
      void load(int x, int y);
      void update();
      void growTail();
      void setDirection(Direction direction);
      Direction direction = down;
    private:
      int speed = 128;
      TailNode* last_node = nullptr;
      TailNode* next_node = nullptr;
  };
}
