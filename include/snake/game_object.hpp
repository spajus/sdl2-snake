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
      int x;
      int y;
      std::string texture_id;
  };
}
