#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Shape.hpp"
#include <SFML/Graphics.hpp>


/*
Classe mère de tous les trucs qui s'affichent à l'écran. Permet d'avoir une fonction draw commune si on stocke
Plusieurs éléments différents dans un tableau.
*/

class Rectangle: public Shape{
public :
    Rectangle(int width, int height, int x, int y, sf::Color color, int outline);
    ~Rectangle();

    void draw(sf::RenderWindow& window);
    void setColor(sf::Color color);
    void setSize(sf::Vector2f size);
    sf::Vector2f getSize();
    sf::Color getColor();

protected:    
    int m_outline;
    sf::RectangleShape m_rectangle;
    sf::Vector2f m_size;
    sf::Vector2i m_position;
    sf::Color getOutColor(sf::Color color);
    sf::Color m_color;
};

#endif