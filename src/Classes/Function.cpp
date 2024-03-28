#include "Function.hpp"
#include <math.h>

Function::Function(){
    m_operation = Null;
    m_left_member = nullptr;
    m_right_member = nullptr;
}

//Analyseur sytaxique
Function::Function(std::string expression){
    int parenthesis_level = 0;
    std::string left_expr = "";
    std::string right_expr = "";
    bool operator_passed = false;
    int operator_level = NULL;
    for (int i = 0; i < expression.size(); i++){
        if (expression[i] == '('){
            parenthesis_level ++;
        }
        else if (expression[i] == ')')
        {
            parenthesis_level --;
        }

    }
}

Function::~Function(){
    delete m_left_member;
    delete m_right_member;
}

float Function::image(std::vector<float> values){
    switch(m_operation){
        float right_val;
        case Addition :
            return m_left_member->image(values) + m_right_member->image(values);
            break;
        case Substraction :
            return m_left_member->image(values) - m_right_member->image(values);
            break;
        case Multiplication :
            return m_left_member->image(values) * m_right_member->image(values);
            break;
        case Division : {
            m_right_member->image(values);
            if (right_val != 0){
                return m_left_member->image(values) * m_right_member->image(values);
            }
            return __FLT_MAX__; //FIXME: Faire un type d'erreur pris en compte par 
            break;
            }   

        case Log : {
            m_right_member->image(values);
            if (right_val > 0){
                return log(m_right_member->image(values));
            }
            throw (1100); //FIXME: Faire un type d'erreur pris en compte par 
            break;
            }

        case Exponential :
            return exp(m_right_member->image(values));
            break;

        case Power :
            return pow(m_left_member->image(values), m_right_member->image(values));
            break;

        case Constant :
            return m_value;
            break;

        case Variable :
            return values[m_value];
            break;

    }
}