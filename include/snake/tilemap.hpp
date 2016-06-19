#pragma once
#include <string>
#include <map>
#include "snake/sdl_includes.hpp"
#include "snake/utils.hpp"

namespace Snake {
  class Tilemap {
    public:
      static Tilemap* instance() {
        if (_instance == nullptr) {
          _instance = new Tilemap();
        }
        return _instance;
      }

      void init(SDL_Renderer* renderer, int tile_w, int tile_h);
      bool addTile(std::string file_path, std::string id);
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
      Tilemap() {}
      ~Tilemap() {}
      static Tilemap* _instance;
      SDL_Renderer* renderer = nullptr;
      std::map<std::string, SDL_Texture*> tiles;
      int tile_h = 0;
      int tile_w = 0;
  };
}
