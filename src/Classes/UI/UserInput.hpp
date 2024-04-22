#ifndef USER_INPUT_HPP
#define USER_INPUT_HPP

#include <SFML/Graphics.hpp>
#include "Rectangle.hpp" 
#include <string>

class UserInput {
public:
    UserInput(int width, int height, int x, int y, sf::Color color);

    void handleEvent(const sf::Event& event);
    void draw(sf::RenderWindow& window);
    std::string getText() const;

    // blinking cursor
    void update();

    void setSize(sf::Vector2f size);
    void setPosition(sf::Vector2f pos);

protected:
    Rectangle input_bar;
    sf::Text text;
    std::string input_text;
    sf::Font font;

    sf::Vector2f m_position;
    sf::Vector2f m_size;

    // blinking cursor
    Rectangle cursor;
    sf::Clock cursor_clock; 
    bool cursor_visible;
};

#endif
