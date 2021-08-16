#pragma once

#include <SFML/Graphics.hpp>

#include <optional>

struct Intersection {
    sf::Vector2f normal;
};

std::optional<Intersection> circleWindowCollision(sf::CircleShape circle, sf::RenderWindow &window);

sf::Vector2f calculateReflectionVec(sf::Vector2f initial_vec, sf::Vector2f normal);
