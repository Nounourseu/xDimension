#include "Rectangle.hpp"

Rectangle::Rectangle(int width, int height, int x, int y, sf::Color color): position(x, y), color(color){
    
}

Rectangle::~Rectangle(){}

void Rectangle::draw() {};