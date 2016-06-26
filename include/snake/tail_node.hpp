#pragma once
#include "snake/game_object.hpp"
#include "snake/path_point.hpp"
#include <queue>

namespace Snake {
  class TailNode : public GameObject {
    public:
      TailNode() {};
      ~TailNode() {};
      void addTo(GameObject* parent);
      void addPath(PathPoint* path_point);
      void update();
      TailNode* next_node = nullptr;
    private:
      int speed = 129;
      std::queue<PathPoint*> path;
  };
}
