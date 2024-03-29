#ifndef LABEL_HPP
#define LABEL_HPP

#include <SFML/Graphics.hpp>

class Label {
    public:
        Label(const char string[], unsigned int characterSize, int x, int y, sf::Color color);
        ~Label();
        unsigned int getLen();
        unsigned int getWidth();
        unsigned int getHeight();

        void changePos(int x, int y);
        
        void draw(sf::RenderWindow& window);

    protected:
        sf::Text text;
        sf::Font font;
        unsigned int m_len;
};

#endif