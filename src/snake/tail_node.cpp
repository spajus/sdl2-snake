#include "snake/tail_node.hpp"
#include "snake/utils.hpp"

const double Snake::TailNode::MAX_DIST = 4;

void Snake::TailNode::addTo(GameObject* parent) {
  GameObject::load("snake_body", parent->x, parent->y);
  parent->addChild(this);
  x = parent->x;
  y = parent->y;
}

void Snake::TailNode::addPath(PathPoint* path_point) {
  if (path.empty()) {
    if (distanceTo(path_point->x, path_point->y) > TailNode::MAX_DIST) {
      path.push(path_point);
    }
  }
}

void Snake::TailNode::update() {
  GameObject::update();
  if (next_node != nullptr) {
    next_node->speed_delta = speed_delta;
    if (!next_node->path.empty()) {
      PathPoint* last_path = next_node->path.back();
      if (distanceTo(last_path->x, last_path->y) > TailNode::MAX_DIST) {
        next_node->addPath(new PathPoint(x, y));
      }
    } else {
      if (distanceTo(next_node->x, next_node->y) > TailNode::MAX_DIST) {
        next_node->addPath(new PathPoint(x, y));
      }
    }
  }
  if (path.empty()) {
    return;
  }
  PathPoint* target = path.front();
  double distance = moveTowards(target);
  if (distance > MAX_DIST) {
    distance = moveTowards(target);
  }
  if (distance < MAX_DIST) {
    path.pop();
    if (next_node != nullptr) {
      next_node->addPath(target);
    } else {
      delete target;
    }
  }
}

double Snake::TailNode::moveTowards(PathPoint* target) {
  if (speed_delta > MAX_DIST) {
    speed_delta = MAX_DIST;
  }
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
  }
  return distanceTo(target->x, target->y);
}
