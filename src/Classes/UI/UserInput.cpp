#include "UserInput.hpp"
#include <iostream>
#include <string.h>

UserInput::UserInput(int width, int height, int x, int y, sf::Color color) 
    : 
    input_bar(width, height, x, y, color), 
    input_text(""), 
    cursor_visible(true), 
    cursor(2, height*0.6, x + 6, y + height/4, sf::Color(0, 150, 0)),
    m_position(x, y),
    m_size(width, height)
    {
    if (!font.loadFromFile("Fonts/arial.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
    }
    text.setFont(font);
    text.setCharacterSize(height/2);
    text.setPosition(x + 5, y + height/4);
    text.setFillColor(sf::Color::Black);

}

void UserInput::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode < 128 && event.text.unicode != 8) {
            if (text.getLocalBounds().width < m_size.x-5-m_size.y/4) {
                input_text += static_cast<char>(event.text.unicode);
                text.setString(input_text);
            }
        }
        else if (event.text.unicode == 8 && !input_text.empty()) { // backspace
            input_text.pop_back();
            text.setString(input_text);
        }
    }
}

void UserInput::draw(sf::RenderWindow& window) {
    input_bar.draw(window);
    window.draw(text);

    if (cursor_visible) {
        cursor.draw(window);
    }
}

std::string UserInput::getText() const {
    return input_text;
}


void UserInput::update() {
    // blinkink every 0.5 seconds
    if (cursor_clock.getElapsedTime().asSeconds() > 0.5) {
        cursor_visible = !cursor_visible;
        cursor_clock.restart();
    }
    float textwidth = text.getLocalBounds().width;
    cursor.setPosition(sf::Vector2f(m_position.x + 6 + textwidth, m_position.y + m_size.y/4));
}
