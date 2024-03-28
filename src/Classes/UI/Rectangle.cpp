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
    int change = 30;
    int rgb[] = {color.r, color.g, color.b};
    for (int i=0; i<3; i++) {
        if (rgb[i]<change) {rgb[i] = 0;}
        else {rgb[i] -= change;}
    }
    return sf::Color(
        static_cast<sf::Uint8>(rgb[0]),
        static_cast<sf::Uint8>(rgb[1]),
        static_cast<sf::Uint8>(rgb[2])
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