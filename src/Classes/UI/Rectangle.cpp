#include "Rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(int width, int height, int x, int y, sf::Color color, int outline = 5): m_position(x, y), m_size(width, height), m_outline(outline) {
    
    this->setColor(color);
    //Plus efficace de le mettre ici, on ne perd pas de temps à redéfinir les paramètrs visuels du rectangle

    m_rectangle.setSize(m_size);
    m_rectangle.setOutlineThickness(m_outline);
    m_rectangle.setPosition(m_position.x, m_position.y);
}

Rectangle::~Rectangle(){

}

sf::Color Rectangle::getOutColor(sf::Color color){
    return sf::Color(
        static_cast<sf::Uint8>(color.r * 1.2),
        static_cast<sf::Uint8>(color.g * 1.2),
        static_cast<sf::Uint8>(color.b * 1.2)
    );
}


void Rectangle::setColor(sf::Color color){
    sf::Color OUTcolor = this->getOutColor(color);
    std::cout << "R: " << static_cast<int>(OUTcolor.r) << std::endl;
    std::cout << "G: " << static_cast<int>(OUTcolor.g) << std::endl;
    std::cout << "B: " << static_cast<int>(OUTcolor.b) << std::endl;

    m_rectangle.setOutlineColor(OUTcolor);
    m_rectangle.setFillColor(color);
}



void Rectangle::draw(sf::RenderWindow& window) {
    window.draw(m_rectangle);
};