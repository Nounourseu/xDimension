#ifndef LABEL_HPP
#define LABEL_HPP

#include <SFML/Graphics.hpp>

class Label {
    public:
        Label(const char string[], unsigned int characterSize, int x, int y, sf::Color color);
        ~Label();
        
        void draw(sf::RenderWindow& window);

    protected:
        sf::Text text;
        sf::Font font;
        unsigned int len;
};

#endif