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

    sf::Vector2i m_position;
    int m_outline;
    void draw(sf::RenderWindow& window);

    sf::Color getOutColor(sf::Color color);

    void setColor(sf::Color color);

protected:    
    sf::RectangleShape m_rectangle;
    sf::Vector2f m_size;
};

#endif