#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>


int main(int argc, char *argv[]) {
    //
    sf::RenderWindow window(sf::VideoMode(800, 600), "MyWindow", sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close);

    sf::RectangleShape rect(sf::Vector2f(150.f, 90.f));
    rect.setFillColor(sf::Color(255, 0, 0, 255));
    rect.setPosition(sf::Vector2f(15.f, 20.f));

    // Game loop
    while (window.isOpen()) {
        //

        // Input
        sf::Event event;
        while (window.pollEvent(event)) {
            // Closed event
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            // Keyboard event
            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code)  {
                    case sf::Keyboard::Escape:
                        window.close();
                        break;

                    case sf::Keyboard::A:
                        rect.move(sf::Vector2f(-5.f, 0.f));
                        break;
                    
                    case sf::Keyboard::D:
                        rect.move(sf::Vector2f(5.f, 0.f));
                        break;

                    default:
                        break;
                }
            }

            // Mouse event
            if (event.type == sf::Event::MouseButtonReleased) {
                switch (event.mouseButton.button) {
                    case sf::Mouse::Button::Left:
                        std::cout << "x: " << event.mouseButton.x << std::endl;
                        std::cout << "y: " << event.mouseButton.y << std::endl;
                        break;

                    default:
                        break;
                }
            }
        }

        // Rendering
        window.clear(sf::Color(0, 0, 255, 255));

        window.draw(rect);

        window.display();
    }

    return 0;
}
