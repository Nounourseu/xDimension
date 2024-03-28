#include "TestPoint.hpp"

TestPoint::TestPoint(int x, int y, int size, sf::Color color = sf::Color::White) : position(x, y), color(color) {
    rectangle.setSize(sf::Vector2f(size, size));
    rectangle.setFillColor(color);
    rectangle.setPosition(position.x - size/2, position.y - size/2); // Rectangle centred arround the point
}
TestPoint::~TestPoint() {};

void TestPoint::draw(sf::RenderWindow& window) {
    window.draw(rectangle);
}
