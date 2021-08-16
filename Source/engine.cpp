#include "engine.hpp"


Engine::Engine() {
    ;
}

void Engine::initialiseWindow(std::string title, sf::VideoMode size, unsigned int flags, unsigned int frames_per_second) {
    window.create(size, title, flags);
    
    this->frames_per_second = frames_per_second;
    window.setFramerateLimit(60);
    
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
    ;
}

sf::RenderWindow &Engine::getWindow() {
    return window;
}

unsigned int Engine::getFramesPerSecond() {
    return frames_per_second;
}

void Engine::destroy() {
    window.close();
}
