#pragma once
#include <string>
namespace Snake {
  class GameObject {
    public:
      void load(std::string texture_id, int x, int y);
      void draw();
      void update();
      void clean();

    protected:
      float x;
      float y;
      std::string texture_id;
      int last_update = 0;
      double time_delta;
  };
}
