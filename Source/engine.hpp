#include "input_manager.hpp"

#include <SFML/Graphics.hpp>

#include <string>


class Engine {
private:
    sf::RenderWindow window;
    InputManager input_manager;

public:
    Engine();

    void initialiseWindow(std::string title, sf::VideoMode size, unsigned int flags);

    bool isRunning();

    void updateInput();
    void render();

    void destroy();
};
