#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include "Classes/Classes.hpp"

void testDoNothing() {
    printf("Clicked");
}

float testFunc(float x) {
    // y = x^2 + 3
    return x*x+3;
    }

int main()
{
    // sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML Works !", sf::Style::Fullscreen);
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML Works !", sf::Style::Default);


    int width = window.getSize().x;
    int height = window.getSize().y;

    // Point rouge au centre
    TestPoint point(width/2, height/2, 3, sf::Color::Red);

    // Rectangle
    Rectangle rect(100, 200, 300, 300, sf::Color(0,150,0), 10);

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
    Segment diag(100,200, 600, 100, sf::Color::Red);

    Button otherbut(600, 200, 600, 100, "other but", testDoNothing, sf::Color(0,0,250));

    TestPoint graph[1920];

    std::pair<float, float> xdef = std::make_pair(-10.0f, 5.0f);
    std::pair<float, float> ydef = std::make_pair(-10.0f, 10.0f);

    Draw2D fonc_test(xdef, ydef, &testFunc, &window);


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
            if (event.type == sf::Event::MouseLeft) {
                int mouseX = sf::Mouse::getPosition().x;
                int mouseY = sf::Mouse::getPosition().y;
                for (int i=0; i<Button::nbInstances(); i++) {
                    Button::getInstance(i)->click(mouseX, mouseY);
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
        otherbut.draw(window);


        diag.draw(window);

        fonc_test.draw();

        window.display();
    }

    return 0;
}