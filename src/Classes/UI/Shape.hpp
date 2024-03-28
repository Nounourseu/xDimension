#ifndef XDMSHAPE_HPP
#define XDMSHAPE_HPP

/*
Classe mère de tous les trucs qui s'affichent à l'écran. Permet d'avoir une fonction draw commune si on stocke
Plusieurs éléments différents dans un tableau.
*/

class Shape{
public :
    Shape();
    ~Shape();
    virtual void draw();
};

#endif