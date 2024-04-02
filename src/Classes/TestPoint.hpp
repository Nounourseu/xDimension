#ifndef TESTPOINT_HPP
#define TESTPOINT_HPP

#include <SFML/Graphics.hpp>

class TestPoint {
public:
    TestPoint(int x = 0, int y = 0, int size = 0, sf::Color color = sf::Color::Red);
    ~TestPoint();
    void draw(sf::RenderWindow& window);
    void rebuild(int x, int y, int size, sf::Color color = sf::Color::Red);
    sf::Vector2i getPos();

protected:
    sf::Vector2i m_position;
    sf::Color m_color;
    sf::RectangleShape rectangle;
};

#endif