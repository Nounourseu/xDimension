#include "Point.hpp"

Point::Point(std::vector<float> pos, sf::Color color) : m_color(color){
    m_dim = pos.size();
    for (int i = 0; i < m_dim; i++){
        m_pos.push_back(pos[i]);
    }
    m_repr = sf::Vertex(sf::Vector2f(this->get2D()), m_color);
}

Point::~Point(){
    
}

void Point::draw(sf::RenderWindow& window){
    window.draw(&m_repr, 1, sf::Points);
}

sf::Vector2i Point::get2D(){
    if (m_dim == 2){
        return sf::Vector2i(int(m_pos[0]), int(m_pos[1]));
    }
    else {
        //Code tellement génial qu'il est pas affiché par la machine.
    }
    throw(1000);
}
