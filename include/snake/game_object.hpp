#pragma once
#include <string>
#include <vector>
namespace Snake {
  class GameObject {
    public:
      void load(std::string texture_id, double x, double y);
      virtual void render();
      virtual void update();
      void setAnchorPoint();
      void clean();
      virtual void addChild(GameObject* child);
      virtual double distanceTo(GameObject* other);
      virtual double distanceTo(double x, double y);
      GameObject* parent = nullptr;
      std::vector<GameObject*> children;
      double x = 0;
      double y = 0;

    protected:
      std::string texture_id;
      int last_update = 0;
      double time_delta;
  };
}
