#include "engine.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>


int main(int argc, char *argv[]) {
    Engine engine;
    engine.initialiseWindow("MyWindow", sf::VideoMode(800, 600), sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close);

    // Game loop
    while (engine.isRunning()) {
        engine.updateInput();

        if (InputManager::isKeyPressed(sf::Keyboard::Key::W)) {
            std::cout << "W IS PRESSED" << std::endl;
        }
        if (InputManager::isKeyHeld(sf::Keyboard::Key::W)) {
            std::cout << "W IS HELD" << std::endl;
        }
        if (InputManager::isKeyReleased(sf::Keyboard::Key::W)) {
            std::cout << "W IS RELEASED" << std::endl;
        }

        engine.render();
    }

    return 0;
}
