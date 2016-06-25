#pragma once
#include <string>
#include <vector>
namespace Snake {
  class GameObject {
    public:
      void load(std::string texture_id, float x, float y);
      virtual void render();
      virtual void update();
      void clean();
      virtual void addChild(GameObject* child);
      virtual float distanceTo(GameObject* other);
      virtual float getX() const { return x; }
      virtual float getY() const { return y; }
      virtual void setX(float x) { this->x = x; }
      virtual void setY(float y) { this->y = y; }

      GameObject* parent = nullptr;
      std::vector<GameObject*> children;

    protected:
      std::string texture_id;
      int last_update = 0;
      double time_delta;
      float x = 0;
      float y = 0;
  };
}
