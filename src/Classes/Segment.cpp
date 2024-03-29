#include "Segment.hpp"
#include <SFML/Graphics.hpp>

Segment::Segment(int xA, int yA, int xB, int yB, unsigned int thickness)
    : start(xA, yA), end(xB, yB), m_thickness(thickness) 
    {}

void Segment::draw(sf::RenderWindow& window) const {
    sf::Vertex line[] = {
        sf::Vertex(start, sf::Color::White),
        sf::Vertex(end, sf::Color::White)
    };

    window.draw(line, m_thickness, sf::Lines);
}
