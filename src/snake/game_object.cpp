#include "snake/game_object.hpp"
#include "snake/tilemap.hpp"

void Snake::GameObject::load(std::string texture_id, int x, int y) {
  this->x = x;
  this->y = y;
  this->texture_id = texture_id;
}

void Snake::GameObject::draw() {
  Tilemap::instance()->draw(texture_id, x, y);
}
