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
      void init(SDL_Renderer* renderer, int tileW, int tileH);
      bool addTile(std::string filePath, std::string id);
      /**
       * Draw single tile at x, y
       */
      void draw(std::string id, int x, int y);
      /**
       * Fill rectangle with looping tile
       */
      void fillWith(std::string id, int x, int y, int w, int h);
      void clean();
    private:
      SDL_Renderer* m_pRenderer = 0;
      std::map<std::string, SDL_Texture*> m_tiles;
      int tileH = 0;
      int tileW = 0;
  };
}
