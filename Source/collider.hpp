#pragma once

#include <SFML/Graphics.hpp>

#include <optional>


struct Intersection {
    sf::Vector2f normal;
};

std::optional<Intersection> circleWindowCollision(sf::CircleShape circ, sf::RenderWindow &window);
std::optional<Intersection> circleCircleCollision(sf::CircleShape circ1, sf::CircleShape circ2);

sf::Vector2f calculateReflectionVec(sf::Vector2f initial_vec, sf::Vector2f normal);
