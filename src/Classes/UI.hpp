#ifndef UI_HPP
#define UI_HPP
#include "Button.hpp"

#include <SFML/Graphics.hpp>

class UI {
    public:
        UI(int type);
        ~UI();
        void start(int type);
        void hide();
    
};

#endif