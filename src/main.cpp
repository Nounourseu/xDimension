#include <SFML/Graphics.hpp>
#include <iostream>

// J'ai fait la class ici pcq j'arrive pas à include SFML dans Point.hpp
class Point {
public:
    Point(int x, int y, int size, sf::Color color = sf::Color::White) : position(x, y), color(color) {
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