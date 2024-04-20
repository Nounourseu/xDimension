#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include "Classes/Classes.hpp"

void testDoNothing(void) {
    printf("testDoNothing successfully called\n");
}

float testFunc(float x) {
    // y = x^2 + 3
    return x*x+3;
    }

int main()
{

    // //sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML Works !", sf::Style::Fullscreen);
    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML Works !", sf::Style::Default);
    // sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Works !");

    Function test("(3*x) + y");
    

    int width = window.getSize().x;
    int height = window.getSize().y;

    // Point rouge au centre
    TestPoint point(width/2, height/2, 3, sf::Color::Red);

    // Rectangle
    Rectangle rect(100, 200, 300, 300, sf::Color(0, 150, 0));

    // Label
    Label lab("HelloW", 40, 700, 100, sf::Color::White);

    // Bouton 
    Button but(100, 40, 600, 700, "Appuie stp", testDoNothing, sf::Color(0,0,250));
    Button but1(200, 40, 600, 650, "Appuie stp", testDoNothing, sf::Color(100,0,250));
    Button but2(400, 40, 600, 600, "Appuie stp", testDoNothing, sf::Color(0,100,50));
    Button but3(600, 40, 600, 550, "Appuie stp", testDoNothing, sf::Color(150,0,50));
    Button but4(800, 40, 600, 500, "Appuie stp", testDoNothing, sf::Color(200,100,50));
    Button but5(1000, 40, 600, 400, "Appuie stp", testDoNothing, sf::Color(0,250,250));

    // Segment
    Segment diag(100,200, 600, 100, sf::Color::Red);

    Button otherbut(600, 200, 600, 100, "other but", testDoNothing, sf::Color(0,0,250));

    TestPoint graph[1920];

    std::pair<float, float> xdef = std::make_pair(-10.0f, 5.0f);
    std::pair<float, float> ydef = std::make_pair(-10.0f, 10.0f);

    Draw2D fonc_test(xdef, ydef, &testFunc, &window);

    UserInput input(200, 50, 900, 900, sf::Color::White);

    int printage = 0;
    while (window.isOpen())
    {
        printage++;

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

            input.handleEvent(event);

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    int mouseX = event.mouseButton.x;
                    int mouseY = event.mouseButton.y;
                    for (int i=0; i<Button::nbInstances(); i++) {
                        void (*onclickFunction)() = Button::getInstance(i)->click(mouseX, mouseY);
                        if (onclickFunction!=nullptr) {
                            onclickFunction();
                        }
                        } 
                    }
            }
        }

        window.clear();

        point.draw(window);
        rect.draw(window);
        lab.draw(window);

        but.update();
        but1.update();
        but2.update();
        but3.update();
        but4.update();
        but5.update();
        otherbut.update();

        input.update();

        but.draw(window);
        but1.draw(window);
        but2.draw(window);
        but3.draw(window);
        but4.draw(window);
        but5.draw(window);
        otherbut.draw(window);


        diag.draw(window);

        fonc_test.draw();

        input.draw(window);

        window.display();
    // if(printage%100==0){printf("\npointer in main.cpp window loop : %p\n", testDoNothing);}
    }

    return 0;
}