#include "snake/tilemap.hpp"

void Snake::Tilemap::init(SDL_Renderer* renderer) {
  m_pRenderer = renderer;
}

bool Snake::Tilemap::addTile(std::string filePath, std::string id) {
  SDL_Surface* pTempSurface = IMG_Load(filePath.c_str());

  if (pTempSurface == 0) {
    Utils::logSDLError(std::cerr, "Image load fail");
    return false;
  }

  SDL_Texture* pTexture = SDL_CreateTextureFromSurface(
      m_pRenderer, pTempSurface);

  if (pTexture == 0) {
    Snake::Utils::logSDLError(std::cerr,
        "Could not create texture: " + filePath);
    return false;
  }

  SDL_FreeSurface(pTempSurface);

  if (pTexture != 0) {
    m_tiles[id] = pTexture;
    return true;
  }

  Snake::Utils::logSDLError(std::cerr, "Could not load image: " + filePath);
  return false;
}

void Snake::Tilemap::draw(std::string id, int x, int y, int w, int h) {
  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = 0;
  srcRect.y = 0;
  srcRect.w = w;
  srcRect.h = h;

  destRect.x = x;
  destRect.y = y;
  destRect.w = w;
  destRect.h = h;

  SDL_RenderCopyEx(
      m_pRenderer, m_tiles[id], &srcRect, &destRect, 0, 0, SDL_FLIP_NONE);
}

void Snake::Tilemap::clean() {
}
