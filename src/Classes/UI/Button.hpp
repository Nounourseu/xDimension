#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include "Rectangle.hpp"
#include "Label.hpp"

class Button {
    public:
        Button(int width, int height, int x, int y, const char text[], void (*m_onclick)(), sf::Color color);
        ~Button();
        void (*m_onclick)();
        void draw(sf::RenderWindow& window);
        sf::Vector2i getPos();

    
    protected:
        sf::Vector2i size;
        sf::Vector2i m_position;
        char text[20];
        sf::Color color;  
        sf::Color calculateTextColor(sf::Color);
        sf::Vector2i cursor;

        // Homemade objects
        Rectangle rect;   
        Label label;   
};

#endif