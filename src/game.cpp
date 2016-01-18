#include <SDL.h>
namespace Snake {
  class Game {
    private:
      void logSDLError(std::ostream &os, const std::string &msg) {
        os << msg << " Error: " << SDL_GetError() << std::endl;
      }
    public:
      void init() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
          logSDLError(std::cout, "SDL_Init");
        }
      }
      ~Game() {
        SDL_Quit();
      }
  };
}
