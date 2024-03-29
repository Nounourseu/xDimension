#include "Segment.hpp"
#include <SFML/Graphics.hpp>

Segment::Segment(int xA, int yA, int xB, int yB)
    : start(xA, yA), end(xB, yB) 
    {}

void Segment::draw(sf::RenderWindow& window) const {
    sf::Vertex line[] = {
        sf::Vertex(start, sf::Color::White),
        sf::Vertex(end, sf::Color::White)
    };

    window.draw(line, 2, sf::Lines);
}
