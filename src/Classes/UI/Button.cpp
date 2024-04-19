#include <string.h>
#include "Button.hpp"
#include "Rectangle.hpp"
#include "Label.hpp"

int Button::nb_instances = 0;
Button* Button::instances[20];

Button::Button(int width, int height, int x, int y, const char text[], void (*m_onclick)(), sf::Color color)
    : m_size(width, height), m_position(x, y), color(color),
      rect(width, height, x, y, color, 5),
      label(text, height/2, x, y, calculateTextColor(color))
       {
        label.changePos((width-label.getWidth())/2 + x, (height-label.getHeight())/4 + y);
        instances[nb_instances] = this;
        nb_instances++;
}

Button::~Button() {}

void Button::draw(sf::RenderWindow& window) {
    rect.draw(window);
    label.draw(window);
}

sf::Color Button::calculateTextColor(sf::Color backgroundColor) {
    // Calcul de la luminance de backgroundColor (les coefs c'est chatGPT)
    float luminance = (0.2126f * backgroundColor.r + 0.7152f * backgroundColor.g + 0.0722f * backgroundColor.b);
    return (luminance < 1280) ? sf::Color::White : sf::Color::Black;
}

sf::Vector2i Button::getPos() {
    return m_position;
}

void Button::click(int mousex, int mousey) {
    if (
        (m_position.x <= mousex) and (m_position.x + m_size.x >= mousex)
        and
        (m_position.y <= mousey) and (m_position.y + m_size.y >= mousey)
    ) {
        m_onclick();
    }
}

int Button::nbInstances() {
        return nb_instances;
    }

Button* Button::getInstance(int index) {
    if (index >= 0 && index < nb_instances) {
        return instances[index]; // Return pointer to Button 
    } else {
        return nullptr; // Return null pointer
    }
}