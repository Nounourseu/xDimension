#ifndef XDMSEGMENT_HPP
#define XDMSEGMENT_HPP

#include <SFML/Graphics.hpp>

class Segment {
public:
    Segment(int xA, int yA, int xB, int yB);

    void draw(sf::RenderWindow& window) const;

protected:
    sf::Vector2f start;
    sf::Vector2f end;
    unsigned int m_thickness;
};

#endif