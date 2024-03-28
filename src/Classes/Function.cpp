#include "Function.hpp"
#include <math.h>

Function::Function(){
    m_operation = Null;
    m_left_member = nullptr;
    m_right_member = nullptr;
}

Function::Function(std::string expression){
    
}

Function::~Function(){
    delete m_left_member;
    delete m_right_member;
}

float Function::image(std::vector<float> values){
    switch(m_operation){
        case Addition :
            return m_left_member->image(values) + m_right_member->image(values);
        case Substraction :
            return m_left_member->image(values) - m_right_member->image(values);
        case Multiplication :
            return m_left_member->image(values) * m_right_member->image(values);
        case Division :
            float right_val = m_right_member->image(values);
            if (right_val != 0){
                return m_left_member->image(values) * m_right_member->image(values);
            }
            return __FLT_MAX__; //FIXME: Faire un type d'erreur pris en compte par 

        case Log :
            float right_val = m_right_member->image(values);
            if (right_val > 0){
                return log(m_right_member->image(values));
            }
            throw (1100); //FIXME: Faire un type d'erreur pris en compte par 

        case Exponential :
            return exp(m_right_member->image(values));

        case Power :
            return pow(m_left_member->image(values), m_right_member->image(values));

        case Constant :
            return m_value;

        case Variable :
            values[m_value];

    }
}