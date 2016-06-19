#pragma once
#include <string>
#include <map>
#include "snake/sdl_includes.hpp"
#include "snake/utils.hpp"

namespace Snake {
  class Tilemap {
    public:
      Tilemap() {}
      ~Tilemap() {}
      void init(SDL_Renderer* renderer);
      bool addTile(std::string filePath, std::string id);
      void draw(std::string id, int x, int y, int w, int h);
      void clean();
    private:
      SDL_Renderer* m_pRenderer = 0;
      std::map<std::string, SDL_Texture*> m_tiles;
      SDL_Texture* grass = 0;
  };
}
