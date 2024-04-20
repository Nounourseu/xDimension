#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include "Rectangle.hpp"
#include "Label.hpp"

class Button {
public:
    static int nbInstances();
    static Button* getInstance(int index);

    Button(int width, int height, int x, int y, const char text[], void (*onclick)(), sf::Color color);
    ~Button();

    void draw(sf::RenderWindow& window);
    sf::Vector2f getPos();
    void (*click(int mousex, int mousey))();
    void update();

protected:
    static int nb_instances;
    static Button* instances[20]; //Modifier le max si besoin (20)

    sf::Vector2f m_size;
    sf::Vector2f m_position;
    char text[20];
    sf::Color m_color;  
    sf::Color calculateTextColor(sf::Color);
    sf::Vector2i cursor;

    // Homemade objects
    Rectangle rect;   
    Label label;
    // Function pointer declaration
    void (*m_onclick)();
    bool clicked = false; 
    sf::Clock timer;
};

#endif