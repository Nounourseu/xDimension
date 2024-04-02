#ifndef DRAW2D_HPP
#define DRAW2D_HPP
#include <SFML/Graphics.hpp>
#include "TestPoint.hpp"

class Draw2D {
    public:
        Draw2D(std::pair<float, float>& xdef, std::pair<float, float>& ydef, float (*func)(float x), sf::RenderWindow* window, sf::Color color = sf::Color::Red);
        ~Draw2D();
        void draw();

    protected:
        std::pair<float, float>& m_xdef;
        std::pair<float, float>& m_ydef;
        float (*m_func)(float x); 
        TestPoint m_points[1920];
        float m_pas;
        float m_ratio;
        sf::Vector2u m_winsize;
        sf::RenderWindow* m_window;
        sf::Vector2i prev_pos;
        sf::Vector2i new_pos;
        sf::Color m_color;
};

#endif