#include <string.h>
#include "Button.hpp"
#include "Rectangle.hpp"
#include "Label.hpp"

Button::Button(int width, int height, int x, int y, const char text[], void (*m_onclick)(), sf::Color color)
    : size(width, height), position(x, y), color(color),
      rect(width, height, x, y, color, 5),
      label(text, height/2, x, y, calculateTextColor(color))
       {
        label.changePos((width-label.getWidth())/2 + x, (height-label.getHeight())/2 + y);
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


