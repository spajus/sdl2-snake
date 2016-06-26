#include "snake/tail_node.hpp"
#include "snake/utils.hpp"

void Snake::TailNode::addTo(GameObject* parent) {
  GameObject::load("snake_body", parent->x, parent->y);
  parent->addChild(this);
  x = parent->x;
  y = parent->y;
}

void Snake::TailNode::addPath(PathPoint* path_point) {
  path.push(path_point);
}

void Snake::TailNode::update() {
  if (path.empty()) {
    if (distanceTo(parent) > 32) {
      addPath(new PathPoint(parent->x, parent->y));
    }
  }
  if (path.empty()) {
    return;
  }
  PathPoint* target = path.front();
  GameObject::update();
  double speed_delta = speed * time_delta;
  if (distanceTo(target->x, target->y) > speed_delta) {
    if (x < target->x) {
      x += speed_delta;
    }
    if (x > target->x) {
      x -= speed_delta;
    }
    if (y < target->y) {
      y += speed_delta;
    }
    if (y > target->y) {
      y -= speed_delta;
    }
  } else {
    path.pop();
    if (next_node != nullptr) {
      next_node->addPath(target);
    } else {
      delete target;
    }
  }
}
