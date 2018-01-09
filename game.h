#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "utils.h"

namespace GameSpace {
    class RenderObject : public sf::Sprite {
    public:
        RenderObject(std::string filename);
    private:
        sf::Texture texture;
    };

    class Game {
    public:
        void run();
        Game* setFPS(float fps);
    private:
        float fps;
        sf::Clock clock;
        sf::RenderWindow* window;
        RenderObject* coolSquare;

        void setup();
        void update(float dt);
        void draw();
        void loop();
        void cleanup();
    };
}