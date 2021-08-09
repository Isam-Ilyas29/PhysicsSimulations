#include "engine.hpp"


Engine::Engine() {
    ;
}

void Engine::initialiseWindow(std::string title, sf::VideoMode size, unsigned int flags) {
    window.create(size, title, flags);
    window.setKeyRepeatEnabled(false);
}

bool Engine::isRunning() {
    return this->window.isOpen();
}

void Engine::updateInput() {
    input_manager.update();

    sf::Event event;
    
    while (window.pollEvent(event)) {
        // Closed event
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        input_manager.processInput(event);
    }
}

void Engine::render() {
    window.clear(sf::Color(0, 0, 255, 255));

    window.display();
}
