#include "Segment.hpp"
#include <SFML/Graphics.hpp>

Segment::Segment(int xA, int yA, int xB, int yB, sf::Color color)
    : start(xA, yA), end(xB, yB), m_color(color)
    {}
Segment::~Segment() {}

void Segment::draw(sf::RenderWindow& window) const {
    sf::Vertex line[] = {
        sf::Vertex(start, m_color),
        sf::Vertex(end, m_color)
    };

    window.draw(line, 2, sf::Lines);
}
