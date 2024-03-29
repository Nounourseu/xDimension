#ifndef XDMSEGMENT_HPP
#define XDMSEGMENT_HPP

#include <SFML/Graphics.hpp>

class Segment {
public:
    Segment(int xA, int yA, int xB, int yB, sf::Color color = sf::Color::White);

    void draw(sf::RenderWindow& window) const;

protected:
    sf::Vector2f start;
    sf::Vector2f end;
    sf::Color m_color;
    unsigned int m_thickness;
};

#endif