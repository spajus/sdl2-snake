#include "snake/tail_node.hpp"
#include "snake/utils.hpp"

void Snake::TailNode::addTo(GameObject* parent) {
  GameObject::load("snake_body", parent->getX(), parent->getY());
  parent->addChild(this);
  x = parent->getX();
  y = parent->getY();
}

void Snake::TailNode::update() {
  GameObject::update();
  float speed_delta = speed * time_delta;
  if (distanceTo(parent) > 32) {
    if (x < parent->getX()) {
      x += speed_delta;
    }
    else if (x > parent->getX()) {
      x -= speed_delta;
    }
    if (y < parent->getY()) {
      y += speed_delta;
    }
    if (y > parent->getY()) {
      y -= speed_delta;
    }
  }
}
