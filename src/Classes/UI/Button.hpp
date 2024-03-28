#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button {
    public:
        Button(int size,  int x, int y,  char text[20], void (*m_onclick)(), sf::Color color);
        ~Button();
        sf::Vector2i position;
        void (*m_onclick)();
    
    protected:
        int size;
        char text[20];
        sf::Color color;
        
};

#endif