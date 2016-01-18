#pragma once
#include <iostream>
#include <string>
namespace Snake {
  class Game {
    private:
      void logSDLError(std::ostream &os, const std::string &msg);
    public:
      void init();
  };
}
