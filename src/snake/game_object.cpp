#include "snake/game_object.hpp"
#include "snake/tilemap.hpp"
#include <math.h>

void Snake::GameObject::load(std::string texture_id, double x, double y) {
  this->x = x;
  this->y = y;
  this->texture_id = texture_id;
}

void Snake::GameObject::update() {
  if (last_update == 0) {
    last_update = SDL_GetTicks();
  }
  for (GameObject* child : children) {
    child->update();
  }
  int current_time = SDL_GetTicks();
  time_delta = (current_time - last_update) / 1000.0;
  last_update = current_time;
}
void Snake::GameObject::addChild(GameObject* child) {
  this->children.push_back(child);
  child->parent = this;
}

void Snake::GameObject::render() {
  for (GameObject* child : children) {
    child->render();
  }
  Tilemap::instance()->render(texture_id, round(x), round(y));
}

double Snake::GameObject::distanceTo(GameObject* other) {
  return distanceTo(other->x, other->y);
}

double Snake::GameObject::distanceTo(double x, double y) {
  return sqrt(pow(this->x - x, 2) + pow(this->y - y, 2));
}
