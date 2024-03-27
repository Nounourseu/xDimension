#include <SFML/Graphics.hpp>
#include <iostream>

#include "Classes/Point.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    Point point(400, 400, 5, sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        point.draw(window);
        window.display();
    }

    return 0;
}