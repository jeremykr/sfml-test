#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "utils.h"
using namespace sf;
using namespace Utils;
#include "game.h"
using namespace GameSpace;

int main() {
    (new Game())->setFPS(60)->run();
    return 0;
}
