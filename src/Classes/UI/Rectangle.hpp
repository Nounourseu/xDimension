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
    sf::Color m_color;
    sf::Color m_OUTcolor;
    int m_outline;
    void draw(sf::RenderWindow& window);

protected:
    sf::Vector2f m_size;
};

#endif