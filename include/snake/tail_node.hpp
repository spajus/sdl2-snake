#pragma once
#include "snake/game_object.hpp"

namespace Snake {
  class TailNode : public GameObject {
    public:
      TailNode() {};
      ~TailNode() {};
      void addTo(GameObject* parent);
      void update();
    private:
      int speed = 128;
      GameObject* parent;
  };
}
