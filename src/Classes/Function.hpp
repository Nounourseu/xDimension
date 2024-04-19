#ifndef XDMFUNCTION_HPP
#define XDMFUNCTION_HPP

#include <string>
#include <vector>

enum Operations {
    Addition, Substraction, Multiplication, Division, Log, Exponential, Power, Constant, Variable, Null
};

class Function {
public :
    Function();
    Function(std::string expression);
    Function(std::string expression, std::vector<std::string> *variables);
    ~Function();
    
    float image(std::vector<float> values);

protected :
    int m_dimension;
    int m_value = 0;
    std::string m_variable = "";
    bool m_var_host = false;
    Function *m_left_member = nullptr;
    Function *m_right_member = nullptr;
    Operations m_operation;
    std::vector<std::string> *m_variables;

};

#endif