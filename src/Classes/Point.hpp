#ifndef POINT_HPP
#define POINT_HPP

#include <SFML/Graphics.hpp> 

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

#endif 
