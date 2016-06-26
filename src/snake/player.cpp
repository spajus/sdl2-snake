#include "snake/player.hpp"
#include "snake/path_point.hpp"

void Snake::Player::load(int x, int y) {
  GameObject::load("snake_head", x, y);
}

void Snake::Player::update() {
  GameObject::update();
  double speed_delta = speed * time_delta;
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
  }
  last_node = node;
}
