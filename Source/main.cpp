#include "engine.hpp"
#include "collider.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>


int main(int argc, char *argv[]) {
    Engine engine;
    engine.initialiseWindow("MyWindow", sf::VideoMode(800, 600), sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close, 60);

    //
    sf::CircleShape circ(50.f);
    circ.setFillColor(sf::Color(244, 241, 53, 255));
    circ.setPosition(sf::Vector2f(10.f, 10.f));

    sf::Vector2f circ_velocity(125.f, 150.f);

    // Game loop
    while (engine.isRunning()) {
        engine.updateInput();

        // Rendering
        engine.getWindow().clear(sf::Color(0, 0, 255, 255));

        circ.move(sf::Vector2f(circ_velocity.x * 1/engine.getFramesPerSecond(), circ_velocity.y * 1/engine.getFramesPerSecond()));
        if (circleWindowCollision(circ, engine.getWindow()).has_value()) {
            circ_velocity = calculateReflectionVec(circ_velocity, circleWindowCollision(circ, engine.getWindow()).value().normal);
        }

        if (InputManager::isKeyHeld(sf::Keyboard::Key::W)) {
            circ.move(sf::Vector2f(0.f, -4.f));
        }
        if (InputManager::isKeyHeld(sf::Keyboard::Key::A)) {
            circ.move(sf::Vector2f(-4.f, 0.f));
        }
        if (InputManager::isKeyHeld(sf::Keyboard::Key::S)) {
            circ.move(sf::Vector2f(0.f, 4.f));
        }
        if (InputManager::isKeyHeld(sf::Keyboard::Key::D)) {
            circ.move(sf::Vector2f(4.f, 0.f));
        }

        if (InputManager::isKeyPressed(sf::Keyboard::Key::R)) {
            circ.setPosition(sf::Vector2f(10.f, 10.f));
        }

        engine.getWindow().draw(circ);

        engine.getWindow().display();

        //
        if (InputManager::isKeyPressed(sf::Keyboard::Key::Escape)) {
            engine.destroy();
        }
    }

    return 0;
}
