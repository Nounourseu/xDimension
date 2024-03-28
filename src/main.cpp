#include <SFML/Graphics.hpp>
#include <iostream>
#include "Classes/Classes.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML Works !", sf::Style::Fullscreen);

    int width = window.getSize().x;
    int height = window.getSize().y;

    // Point rouge au centre
    TestPoint point(width/2, height/2, 3, sf::Color::Red);

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