#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>
#include "Label.hpp"

Label::Label(const char string[], unsigned int characterSize, int x, int y, sf::Color color) {
    unsigned int len = strlen(string);
    if (!font.loadFromFile("Fonts/arial.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
    }
    text.setString(string);
    text.setCharacterSize(characterSize);
    text.setFillColor(color);
    text.setPosition(x, y);
    text.setFont(font);
}

Label::~Label() {}

void Label::draw(sf::RenderWindow& window) {
    window.draw(text);
}

