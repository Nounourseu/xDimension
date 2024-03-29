#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include "Classes/Classes.hpp"

void testDoNothing() {
    printf("Clicked");
}

int main()
{
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML Works !", sf::Style::Fullscreen);

    int width = window.getSize().x;
    int height = window.getSize().y;

    // Point rouge au centre
    TestPoint point(width/2, height/2, 3, sf::Color::Red);

    // Rectangle
    Rectangle rect(100, 200, 300, 300, sf::Color(0,0,250), 10);

    // Label
    Label lab("HelloW", 40, 700, 100, sf::Color::White);

    // Bouton 
    Button but(100, 40, 600, 700, "Appuie stp", testDoNothing, sf::Color(0,0,250));
    Button but1(200, 40, 600, 650, "Appuie stp", testDoNothing, sf::Color(0,0,250));
    Button but2(400, 40, 600, 600, "Appuie stp", testDoNothing, sf::Color(0,0,250));
    Button but3(600, 40, 600, 550, "Appuie stp", testDoNothing, sf::Color(0,0,250));
    Button but4(800, 40, 600, 500, "Appuie stp", testDoNothing, sf::Color(0,0,250));
    Button but5(1000, 40, 600, 400, "Appuie stp", testDoNothing, sf::Color(0,0,250));

    // Segment
    Segment seg(0,0, 1920, 1080);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed){
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                    window.close();
                }
            }
        }

        window.clear();
        point.draw(window);
        rect.draw(window);
        lab.draw(window);

        but.draw(window);
        but1.draw(window);
        but2.draw(window);
        but3.draw(window);
        but4.draw(window);
        but5.draw(window);

        seg.draw(window);

        window.display();
    }

    return 0;
}