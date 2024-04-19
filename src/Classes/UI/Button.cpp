#include <string.h>
#include "Button.hpp"
#include "Rectangle.hpp"
#include "Label.hpp"

int Button::nb_instances = 0;
Button* Button::instances[20];

Button::Button(int width, int height, int x, int y, const char text[], void (*onclick)(), sf::Color color)
    : m_size(width, height), m_position(x, y), m_color(color), m_onclick(onclick),
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

void (*Button::click(int mousex, int mousey))() {

    if (
        (m_position.x <= mousex) and (m_position.x + m_size.x >= mousex)
        and
        (m_position.y <= mousey) and (m_position.y + m_size.y >= mousey)
    ) {
        clicked = true;
        timer.restart();

        rect.setSize(sf::Vector2f(m_size.x*0.99, m_size.y*0.99));
        
        int darker = 30;
        int rgb[] = {m_color.r, m_color.g, m_color.b};
        for (int i=0; i<3; i++) {
            if (rgb[i]<darker) {rgb[i] = 0;}
            else {rgb[i] -= darker;}
        }  
        rect.setColor(
            sf::Color(
                rgb[0],
                rgb[1],
                rgb[2]
            )
        );
        return m_onclick;
    }
    return nullptr;
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

void Button::update() {
    if (clicked) {
        if (timer.getElapsedTime().asSeconds() > 0.2) {
            rect.setSize(sf::Vector2f(m_size.x, m_size.y)); 
            rect.setColor(m_color);
            clicked = false;
        }
    }
}