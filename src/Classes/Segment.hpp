#ifndef XDMSEGMENT_HPP
#define XDMSEGMENT_HPP

#include <SFML/Graphics.hpp>
#include "UI/Shape.hpp"

class Segment : public Shape {
public:
    Segment(int xA, int yA, int xB, int yB, sf::Color color = sf::Color::White);
    ~Segment();
    void draw(sf::RenderWindow& window) const;

protected:
    sf::Vector2f start;
    sf::Vector2f end;
    sf::Color m_color;
    unsigned int m_thickness;
};

#endif