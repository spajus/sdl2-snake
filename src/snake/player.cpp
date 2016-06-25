#include "snake/player.hpp"

void Snake::Player::load(int x, int y) {
  GameObject::load("snake_head", x, y);
}

void Snake::Player::update() {
  GameObject::update();
  float speed_delta = speed * time_delta;
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

void Snake::Player::growTail() {
  TailNode* node = new TailNode();
  if (tail == nullptr) {
    node->addTo(this);
  } else {
    node->addTo(tail);
  }
  tail = node;
}
