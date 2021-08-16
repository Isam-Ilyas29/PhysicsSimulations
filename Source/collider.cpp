#include "collider.hpp"

#include "math.hpp"


std::optional<Intersection> circleWindowCollision(sf::CircleShape circle, sf::RenderWindow &window) {
    bool should_return = false;
    Intersection intersection;
    intersection.normal = {0.f, 0.f};
    
    // Conditions
    if ((circle.getPosition().x + circle.getRadius() > window.getSize().x) || (circle.getPosition().x + circle.getRadius() < 0)) {
        should_return = true;
        intersection.normal.x = -1;
    }
    if ((circle.getPosition().y + circle.getRadius() > window.getSize().y) || (circle.getPosition().y + circle.getRadius() < 0)) {
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

sf::Vector2f calculateReflectionVec(sf::Vector2f initial_vec, sf::Vector2f normal) {
    sf::Vector2f reflection_vec = initial_vec - (2.f * dot(initial_vec, normal) * normal);

    return reflection_vec;
}
