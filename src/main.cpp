#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Classes/Point.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    std::vector<float> pos;
    pos.push_back(400.0);
    pos.push_back(400.0);
    Point point(pos, sf::Color::Red);

    // --> Point trop petit pour être vu. Regarder si il vaut mieux pas passer par des cercles.

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