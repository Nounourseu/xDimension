#include <string.h>
#include "Button.hpp"
#include "Rectangle.hpp"
#include "Label.hpp"

Button::Button(int width, int height, int x, int y, const char text[], void (*m_onclick)(), sf::Color color)
    : size(width, height), position(x, y), color(color),
      rect(width, height, x, y, color, 5),
      label(text, height*0.6, centerTxt(x, width, height, strlen(text)), y, calculateTextColor(color))
       {
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

int Button::centerTxt(int x, int width, int height, int len) {
    return x + (width-height/2*len)/2;
}

