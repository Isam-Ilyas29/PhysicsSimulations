#include "engine.hpp"
#include "particle.hpp"
#include "collider.hpp"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <cmath>


int main(int argc, char *argv[]) {
    Engine engine;
    engine.initialiseWindow("MyWindow", sf::VideoMode(800, 600), sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close, 60);

    // Create particles
    Particle particle1{sf::CircleShape(100.f), sf::Vector2f(250.f, 150.f), 100};
    particle1.circle.setFillColor(sf::Color(244, 241, 53, 255));
    particle1.circle.setPosition(sf::Vector2f(50.f, 300.f));

    Particle particle2{sf::CircleShape(50.f), sf::Vector2f(-250.f, 150.f), 50};
    particle2.circle.setFillColor(sf::Color(94, 207, 59, 255));
    particle2.circle.setPosition(sf::Vector2f(450.f, 300.f));

    // Game loop
    while (engine.isRunning()) {
        engine.updateInput();

        //
        engine.getWindow().clear(sf::Color(0, 0, 255, 255));

        //
        particle1.circle.move(sf::Vector2f(particle1.velocity.x * 1/engine.getFramesPerSecond(), particle1.velocity.y * 1/engine.getFramesPerSecond()));
        if (circleWindowCollision(particle1.circle, engine.getWindow()).has_value()) {
            particle1.velocity = calculateReflectionVec(particle1.velocity, circleWindowCollision(particle1.circle, engine.getWindow()).value().normal);
        }

        //
        particle2.circle.move(sf::Vector2f(particle2.velocity.x * 1/engine.getFramesPerSecond(), particle2.velocity.y * 1/engine.getFramesPerSecond()));
        if (circleWindowCollision(particle2.circle, engine.getWindow()).has_value()) {
            particle2.velocity = calculateReflectionVec(particle2.velocity, circleWindowCollision(particle2.circle, engine.getWindow()).value().normal);
        }

        // Hardcoded collision test code
        int dist_x = particle1.circle.getPosition().x - particle2.circle.getPosition().x;
        int dist_y = particle1.circle.getPosition().y - particle2.circle.getPosition().y;
        int dist = std::sqrt(std::pow(dist_x, 2) + std::pow(dist_y, 2));

        if ((dist > 0) && (dist < particle1.circle.getRadius() + particle2.circle.getRadius())) {
            particle1.circle.setFillColor(sf::Color(150, 31, 31, 255));
            particle2.circle.setFillColor(sf::Color(150, 31, 31, 255));
        }
        else {
            particle1.circle.setFillColor(sf::Color(244, 241, 53, 255));
            particle2.circle.setFillColor(sf::Color(94, 207, 59, 255));
        }

        // TODO: Reflection vectors for circle-circle collisions (momentum + kinetic energy)

        //
        if (InputManager::isKeyHeld(sf::Keyboard::Key::W)) {
            particle1.circle.move(sf::Vector2f(0.f, -4.f));
        }
        if (InputManager::isKeyHeld(sf::Keyboard::Key::A)) {
            particle1.circle.move(sf::Vector2f(-4.f, 0.f));
        }
        if (InputManager::isKeyHeld(sf::Keyboard::Key::S)) {
            particle1.circle.move(sf::Vector2f(0.f, 4.f));
        }
        if (InputManager::isKeyHeld(sf::Keyboard::Key::D)) {
            particle1.circle.move(sf::Vector2f(4.f, 0.f));
        }

        if (InputManager::isKeyPressed(sf::Keyboard::Key::R)) {
            particle1.circle.setPosition(sf::Vector2f(10.f, 10.f));
        }

        //
        engine.getWindow().draw(particle1.circle);
        engine.getWindow().draw(particle2.circle);

        engine.getWindow().display();

        //
        if (InputManager::isKeyPressed(sf::Keyboard::Key::Escape)) {
            engine.destroy();
        }
    }

    return 0;
}
