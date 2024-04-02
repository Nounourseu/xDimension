#include "TestPoint.hpp"

TestPoint::TestPoint(int x, int y, int size, sf::Color color) : m_position(x, y), m_color(color) {
    rectangle.setSize(sf::Vector2f(size, size));
    rectangle.setFillColor(m_color);
    rectangle.setPosition(m_position.x - size/2, m_position.y - size/2); // Rectangle centred arround the point
}
TestPoint::~TestPoint() {};

void TestPoint::draw(sf::RenderWindow& window) {
    window.draw(rectangle);
}

void TestPoint::rebuild(int x, int y, int size, sf::Color color) {
    m_position=sf::Vector2i(x, y);
    rectangle.setSize(sf::Vector2f(size, size));
    rectangle.setFillColor(color);
    rectangle.setPosition(m_position.x - size/2, m_position.y - size/2); // Rectangle centred arround the point
}

sf::Vector2i TestPoint::getPos() {
    return m_position;
}
