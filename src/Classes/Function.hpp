#ifndef XDMFUNCTION_HPP
#define XDMFUNCTION_HPP

#include <string>
#include <vector>

enum Operations {
    Addition, Substraction, Multiplication, Division, Log, Exponential, Power, Null
};

class Function {
public :
    Function();
    Function(std::string expression);
    ~Function();
    
    float image(std::vector<float> values);

protected :
    int m_dimension;
    Function *m_left_member;
    Function *m_right_member;
    Operations m_operation;

};

#endif