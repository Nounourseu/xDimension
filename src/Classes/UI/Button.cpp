#include "Button.hpp"

Button::Button(int size, int x, int y, char text[20], void (*m_onclick)(), sf::Color color = sf::Color::White): position(x, y), color(color) {
    // en construction
}
Button::~Button() {};

