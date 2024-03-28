#include "Rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(int width, int height, int x, int y, sf::Color color, int outline = 5): m_position(x, y), m_color(color), m_size(width, height), m_outline(outline) {
    m_OUTcolor = sf::Color(
        static_cast<sf::Uint8>(color.r * 1.2),
        static_cast<sf::Uint8>(color.g * 1.2),
        static_cast<sf::Uint8>(color.b * 1.2)
    );
    std::cout << "R: " << static_cast<int>(m_OUTcolor.r) << std::endl;
    std::cout << "G: " << static_cast<int>(m_OUTcolor.g) << std::endl;
    std::cout << "B: " << static_cast<int>(m_OUTcolor.b) << std::endl;

}

Rectangle::~Rectangle(){}

void Rectangle::draw(sf::RenderWindow& window) {
    sf::RectangleShape rectangle;
    rectangle.setSize(m_size);
    rectangle.setOutlineColor(m_OUTcolor);
    rectangle.setFillColor(m_color);
    rectangle.setOutlineThickness(m_outline);
    rectangle.setPosition(m_position.x, m_position.y);
    window.draw(rectangle);
};