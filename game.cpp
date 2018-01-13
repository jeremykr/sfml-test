#pragma once
#include "game.h"
using namespace sf;
using namespace Utils;

namespace GameSpace {

    Texture* Game::loadTexture(std::string filename) {
        Texture* texture = new Texture();
        if ((*texture).loadFromFile(filename)) {
            return texture;
        } else {
            std::cerr << "Error loading texture from file." << std::endl;
            return nullptr;
        }
    }

    void Game::run() {
        setup();
        loop();
        cleanup();
    }

    Game* Game::setFPS(float fps) { 
        this->fps = fps; 
        return this; 
    }

    // Initialize the game window and game objects.
    void Game::setup() {
        window = new RenderWindow(VideoMode(800, 600), "SFML Test Project");
        window->setActive(true);

        Texture* pBoxTex = Game::loadTexture("./resources/images/box.png");

        if (pBoxTex != nullptr) {
            coolSquare = new Sprite(*pBoxTex);
        }
    }

    // Update the game.
    void Game::update(float dt) {
        Vector2f v(0, 0);
        // Move down
        if (Keyboard::isKeyPressed(Keyboard::A)) v += Vector2f(-1, 0);
        // Move right
        if (Keyboard::isKeyPressed(Keyboard::D)) v += Vector2f(1, 0);
        // Move up
        if (Keyboard::isKeyPressed(Keyboard::W)) v += Vector2f(0, -1);
        // Move left
        if (Keyboard::isKeyPressed(Keyboard::S)) v += Vector2f(0, 1);
        coolSquare->move(normalize(v) * (dt * 500));
    }

    // Draw the game objects to the screen.
    void Game::draw() {
        window->clear(Color::Black);
        window->draw(*coolSquare);
        window->display();
    }

    // Execute the game loop, including calls to `update`, `draw`, and `cleanup`.
    void Game::loop() {
        float spf = 1/fps; // Seconds per frame
        float pt = 0.0; // Previous elapsed time
        float ct = 0.0; // Current elapsed time
        float dt; // Time between loops

        while (window->isOpen()) {
            // check all the window's events that were triggered since the last iteration of the loop
            Event event;
            while (window->pollEvent(event)) {
                switch (event.type) {
                    case Event::Closed:
                        window->close();
                        break;
                    default:
                        break;
                }
            }
            // Tick
            ct = clock.getElapsedTime().asMilliseconds() / 1000.0;
            dt = ct - pt;
            pt = ct;

            update(dt);
            
            if (ct > spf) {
                draw();
                clock.restart();
                ct = pt = 0.0;
            }
        }
        cleanup();
    }

    // Clean up the game objects after the game is finished.
    void Game::cleanup() {
        
    }
}