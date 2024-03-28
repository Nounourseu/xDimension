#ifndef TESTPOINT_HPP
#define TESTPOINT_HPP

#include <SFML/Graphics.hpp>

class TestPoint {
public:
    TestPoint(int x, int y, int size, sf::Color color);
    ~TestPoint();
    void draw(sf::RenderWindow& window);

protected:
    sf::Vector2i position;
    sf::Color color;
    sf::RectangleShape rectangle;
};

#endif