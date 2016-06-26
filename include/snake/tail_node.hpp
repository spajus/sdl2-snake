#pragma once
#include "snake/game_object.hpp"
#include "snake/path_point.hpp"
#include <queue>

namespace Snake {
  class TailNode : public GameObject {
    public:
      static const double MAX_DIST;
      TailNode() {};
      ~TailNode() {};
      void addTo(GameObject* parent);
      void addPath(PathPoint* path_point);
      double moveTowards(PathPoint* target);
      void update();
      TailNode* next_node = nullptr;
      std::queue<PathPoint*> path;
      double speed_delta = 0;
  };
}
