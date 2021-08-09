#include "input_manager.hpp"


std::unordered_map<sf::Keyboard::Key, InputManager::KeyState> InputManager::key_states = []() -> std::unordered_map<sf::Keyboard::Key, InputManager::KeyState> {
    std::unordered_map<sf::Keyboard::Key, InputManager::KeyState> key_states;

    for (std::underlying_type_t<sf::Keyboard::Key> i = 0; i < sf::Keyboard::Key::KeyCount; i++) {
        key_states.try_emplace(static_cast<sf::Keyboard::Key>(i), KeyState::NONE);
    }

    return key_states;
}();

InputManager::InputManager() {
    ;
}

void InputManager::update() {
    for (auto [key, key_state] : key_states) {
        // Clear inputs from previous call
        if (key_states[key] == KeyState::RELEASED) {
            key_states[key] = KeyState::NONE;
        }
        // Change state from PRESSED -> HELD
        else if (key_states[key] == KeyState::PRESSED) {
            key_states[key] = KeyState::HELD;
        } 
    }
}

void InputManager::processInput(sf::Event event) {
    // Keyboard event
    if (event.type == sf::Event::KeyPressed) {
        key_states[event.key.code] = KeyState::PRESSED;
    } else if (event.type == sf::Event::KeyReleased) {
        key_states[event.key.code] = KeyState::RELEASED;
    }

    // Mouse event
    if (event.type == sf::Event::MouseButtonReleased) {
        //
    }
}

bool InputManager::isKeyPressed(sf::Keyboard::Key key) {
    return key_states[key] == KeyState::PRESSED;
}

bool InputManager::isKeyHeld(sf::Keyboard::Key key) {
    return key_states[key] == KeyState::HELD;
}

bool InputManager::isKeyReleased(sf::Keyboard::Key key) {
    return key_states[key] == KeyState::RELEASED;
}
