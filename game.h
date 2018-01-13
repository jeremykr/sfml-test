#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "utils.h"

namespace GameSpace {
    class Game {
    public:
        void run();
        Game* setFPS(float fps);
    private:
        float fps;
        sf::Clock clock;
        sf::RenderWindow* window;
        sf::Sprite* coolSquare;

        sf::Texture* loadTexture(std::string filename);

        void setup();
        void update(float dt);
        void draw();
        void loop();
        void cleanup();
    };
}