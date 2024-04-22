#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include "Classes/Classes.hpp"

bool drawfunc = false;
sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML Works !", sf::Style::Fullscreen);
// sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SFML Works !", sf::Style::Default);
// sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Works !");

std::pair<float, float> xdef = std::make_pair(-10.0f, 5.0f);
std::pair<float, float> ydef = std::make_pair(-10.0f, 10.0f);

UserInput input(0, 0, 0, 0, sf::Color::White);

void testDoNothing() {
    printf("testDoNothing successfully called\n");
}

// Function defaultFunc("(3*x)");
Ftest defaultFunc("hello world");

Draw2D f_drawn(xdef, ydef, &defaultFunc, &window);

void drawF() {
    printf("\nDrawF\n");
    // Function f(input.getText());
    if (1==1) {
        // en fonction du nb de variables
        Draw2D f_drawn(xdef, ydef, &defaultFunc, &window);
    }
    else if (2==2)
    {
        // Draw3D
    }
    else {
        // Draw4D
    }
    
    drawfunc = true;
}

int main()
{

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
    Button but1(200, 40, 600, 650, "Appuie stp", testDoNothing, sf::Color(100,0,250));
    Button but2(400, 40, 600, 600, "Appuie stp", testDoNothing, sf::Color(0,100,50));
    Button but3(600, 40, 600, 550, "Appuie stp", testDoNothing, sf::Color(150,0,50));
    Button but4(800, 40, 600, 500, "Appuie stp", testDoNothing, sf::Color(200,100,50));
    Button but5(1000, 40, 600, 400, "Appuie stp", testDoNothing, sf::Color(0,250,250));

    // Segment
    Segment diag(100,200, 600, 100, sf::Color::Red);

    Button otherbut(600, 200, 600, 100, "other but", testDoNothing, sf::Color(0,0,250));

    TestPoint graph[1920];

    // Draw2D fonc_test(xdef, ydef, &testFunc, &window);

    Label txt_fonction2D("f(x) = ", 50, 0, height-75, sf::Color::White);
    input.setSize(sf::Vector2f(width-500, 100));
    input.setPosition(sf::Vector2f(130, height-100));
    Button draw_but(350, 92, width-355, height-97, "Visualiser", drawF, sf::Color(0,0,250));

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

        draw_but.update();
        but1.update();
        but2.update();
        but3.update();
        but4.update();
        but5.update();
        otherbut.update();

        input.update();

        draw_but.draw(window);
        but1.draw(window);
        but2.draw(window);
        but3.draw(window);
        but4.draw(window);
        but5.draw(window);
        otherbut.draw(window);


        diag.draw(window);

        // fonc_test.draw();
        if (drawfunc) {
            f_drawn.draw();
        }

        txt_fonction2D.draw(window);
        input.draw(window);

        window.display();
    // if(printage%100==0){printf("\npointer in main.cpp window loop : %p\n", testDoNothing);}
    }

    return 0;
}