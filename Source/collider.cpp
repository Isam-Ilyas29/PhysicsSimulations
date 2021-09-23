#include "collider.hpp"

#include "math.hpp"

#include <iostream>


std::optional<Intersection> circleWindowCollision(sf::CircleShape circ, sf::RenderWindow &window) {
    bool should_return = false;
    Intersection intersection;
    intersection.normal = {0.f, 0.f};
    
    // Conditions
    if ((circ.getPosition().x + circ.getRadius() > window.getSize().x) || (circ.getPosition().x + circ.getRadius() < 0)) {
        should_return = true;
        intersection.normal.x = -1;
    }
    if ((circ.getPosition().y + circ.getRadius() > window.getSize().y) || (circ.getPosition().y + circ.getRadius() < 0)) {
        should_return = true;
        intersection.normal.y = -1;
    }

    if (should_return) {
        return intersection;
    }
    else {
        return std::nullopt;
    }
}

std::optional<Intersection> circleCircleCollision(sf::CircleShape circ1, sf::CircleShape circ2) {
    bool should_return = false;
    Intersection intersection;
    intersection.normal = {0.f, 0.f};

    //TODO: Calculate normal at circle-circle collision
    
    if (should_return) {
        return intersection;
    }
    else {
        return std::nullopt;
    }
}

sf::Vector2f calculateReflectionVec(sf::Vector2f initial_vec, sf::Vector2f normal) {
    // TODO: Velocity rapidly increases after some time (around 10s)
    sf::Vector2f reflection_vec = initial_vec - (2.f * dot(initial_vec, normal) * normal);

    return reflection_vec;
}
