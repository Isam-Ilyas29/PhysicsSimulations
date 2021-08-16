#pragma once

#include "input_manager.hpp"

#include <SFML/Graphics.hpp>

#include <string>


class Engine {
private:
    sf::RenderWindow window;
    unsigned int frames_per_second;
    InputManager input_manager;

public:
    Engine();

    void initialiseWindow(std::string title, sf::VideoMode size, unsigned int flags, unsigned int frames_per_second);

    bool isRunning();

    void updateInput();
    void render();

    sf::RenderWindow &getWindow();
    unsigned int getFramesPerSecond();

    void destroy();
};
