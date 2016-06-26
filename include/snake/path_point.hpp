#pragma once

namespace Snake {
  class PathPoint {
    public:
      PathPoint(double x, double y) { this->x = x; this->y = y; }
      ~PathPoint() {};
      double x;
      double y;
  };
}
