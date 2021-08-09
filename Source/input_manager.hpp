/*
unnamed namespace
    list of all events

processinput(event)
isXXX

4 states
*/
#include <SFML/Graphics.hpp>

#include <unordered_map>
#include <type_traits>


class InputManager {
private:
    enum class KeyState { NONE, PRESSED, HELD, RELEASED };

    static std::unordered_map<sf::Keyboard::Key, KeyState> key_states;

public:
    InputManager();

    void update();
    void processInput(sf::Event event);

    static bool isKeyPressed(sf::Keyboard::Key key);
    static bool isKeyHeld(sf::Keyboard::Key key);
    static bool isKeyReleased(sf::Keyboard::Key key);
};
