#ifndef POINT_HPP
#define POINT_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.hpp"

class Point : public Shape{
public:
    Point(std::vector<float> pos, sf::Color color = sf::Color::White);
    ~Point();

    void draw(sf::RenderWindow& window);
    sf::Vector2i get2D();

private:
    std::vector<float> m_pos = {};
    int m_dim;
    sf::Color m_color;
    sf::Vertex m_repr;
};

#endif 
