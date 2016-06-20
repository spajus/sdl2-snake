#include "snake/game_object.hpp"
#include "snake/tilemap.hpp"

void Snake::GameObject::load(std::string texture_id, int x, int y) {
  this->x = x;
  this->y = y;
  this->texture_id = texture_id;
}

void Snake::GameObject::update() {
  if (last_update == 0) {
    last_update = SDL_GetTicks();
  }
  int current_time = SDL_GetTicks();
  time_delta = (current_time - last_update) / 1000.0;
  last_update = current_time;
}

void Snake::GameObject::draw() {
  Tilemap::instance()->draw(texture_id, round(x), round(y));
}
