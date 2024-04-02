#include "Draw2D.hpp"
#include "Segment.hpp"
#include <SFML/Graphics.hpp>
#include <stdlib.h>


Draw2D::Draw2D(std::pair<float, float>& xdef, std::pair<float, float>& ydef, float (*func)(float x), sf::RenderWindow* window, sf::Color color)
: m_xdef(xdef), m_ydef(ydef), m_func(func), m_window(window), m_color(color) {
    m_winsize = m_window->getSize();
    m_pas = (xdef.second-xdef.first)/m_winsize.x;
    m_ratio = (ydef.second-ydef.first)/m_winsize.y;

    for (int i=0; i<m_winsize.x; i++) {
        m_points[i].rebuild(i, m_winsize.y - func(i*m_pas-(m_xdef.first*0))/m_ratio, 2, m_color);
    }

}

Draw2D::~Draw2D() {}

void Draw2D::draw() {

    Segment xAxis(  0,
                    -(int)(m_winsize.y)*m_ydef.second/(m_ydef.first-m_ydef.second),
                    m_winsize.x,
                    -(int)(m_winsize.y)*m_ydef.second/(m_ydef.first-m_ydef.second)
                    );

    Segment yAxis(  m_winsize.x*m_xdef.second/(m_xdef.first-m_xdef.second)+m_winsize.x,
                    0,
                    m_winsize.x*m_xdef.second/(m_xdef.first-m_xdef.second)+m_winsize.x,
                    m_winsize.y);

    yAxis.draw(*m_window);
    xAxis.draw(*m_window);

    m_points[0].draw(*m_window);
    for (int i=1; i<m_winsize.x; i++) {
        prev_pos = m_points[i-1].getPos();
        new_pos = m_points[i].getPos();

        m_points[i].draw(*m_window); 
        
        if (abs(new_pos.y - prev_pos.y) > 1) {
            Segment seg(prev_pos.x, prev_pos.y, new_pos.x, new_pos.y, m_color);
            seg.draw(*m_window);
        }
    }
}
