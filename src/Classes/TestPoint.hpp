#ifndef TESTPOINT_HPP
#define TESTPOINT_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.hpp"

class TestPoint {
public:
    TestPoint(int x, int y, int size, sf::Color color = sf::Color::White);
    ~TestPoint();
    void draw(sf::RenderWindow& window);

protected:
    sf::Vector2i position;
    sf::Color color;
    sf::RectangleShape rectangle;
};

#endif