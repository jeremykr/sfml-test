#include "game.h"
using namespace GameSpace;

int main() {
    (new Game())->setFPS(60)->run();
    return 0;
}
