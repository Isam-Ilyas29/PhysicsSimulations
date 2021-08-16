#include "math.hpp"


float dot(sf::Vector2f v1, sf::Vector2f v2) {
    int dot_product = (v1.x * v2.x) + (v1.y * v2.y);

    return dot_product;
}
