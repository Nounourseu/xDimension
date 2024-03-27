#include <SFML/Graphics.hpp>
#include <iostream>

// J'ai fait la class ici pcq j'arrive pas à include SFML dans Point.hpp
class MainPoint {
public:
    MainPoint(int x, int y, int size, sf::Color color = sf::Color::White) : position(x, y), color(color) {
        rectangle.setSize(sf::Vector2f(size, size));
        rectangle.setFillColor(color);
        rectangle.setPosition(position.x - size/2, position.y - size/2); // Rectangle centred arround the point
    }

    void draw(sf::RenderWindow& window) const {
        window.draw(rectangle);
    }

private:
    sf::Vector2i position;
    sf::Color color;
    sf::RectangleShape rectangle;
};


int main()
{
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML Works !", sf::Style::Fullscreen);

    int width = window.getSize().x;
    int height = window.getSize().y;

    // Point rouge au centre
    MainPoint point(width/2, height/2, 3, sf::Color::Red);

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