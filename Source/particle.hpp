#include <SFML/Graphics.hpp>


struct Particle {
    sf::CircleShape circle;
    sf::Vector2f velocity;
    unsigned int mass;
};
