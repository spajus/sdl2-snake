#include "snake/player.hpp"
#include "snake/path_point.hpp"
#include "snake/utils.hpp"

void Snake::Player::load(int x, int y) {
  GameObject::load("snake_head", x, y);
}

void Snake::Player::update() {
  GameObject::update();
  double speed_delta = speed * time_delta;
  next_node->speed_delta = speed_delta;
  switch (direction) {
    case left:
      x -= speed_delta;
      break;
    case right:
      x += speed_delta;
      break;
    case up:
      y -= speed_delta;
      break;
    case down:
      y += speed_delta;
      break;
  }

  if (next_node->collidesWith(this, 0)) {
    // TODO: implement game over
    speed = 0;
  }

  if (!next_node->path.empty()) {
    PathPoint* last_path = next_node->path.back();
    if (distanceTo(last_path->x, last_path->y) > speed_delta) {
      next_node->addPath(new PathPoint(x, y));
    }
  } else {
    if (distanceTo(next_node->x, next_node->y) > speed_delta) {
      next_node->addPath(new PathPoint(x, y));
    }
  }
}

void Snake::Player::setDirection(Direction direction) {
  this->direction = direction;
  next_node->addPath(new PathPoint(x, y));
}

void Snake::Player::growTail() {
  TailNode* node = new TailNode();
  if (next_node == nullptr) {
    node->addTo(this);
    next_node = node;
  } else {
    node->addTo(last_node);
    last_node->next_node = node;
  }
  last_node = node;
}
