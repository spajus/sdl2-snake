#include "snake/player.hpp"

void Snake::Player::load(int x, int y) {
  GameObject::load("snake_head", x, y);
}

void Snake::Player::update() {
  GameObject::update();
  int speed_delta = speed * time_delta;
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



