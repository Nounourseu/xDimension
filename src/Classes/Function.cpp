#include "Function.hpp"
#include <math.h>
#include <iostream>

Function::Function(){
    m_operation = Null;
    m_left_member = nullptr;
    m_right_member = nullptr;
}

//Analyseur sytaxique
Function::Function(std::string expression, std::vector<std::string> *variables){
    m_variables = variables;
    std::cout << expression << std::endl;
    int parenthesis_level = 0;
    std::string left_expr = "";
    std::string right_expr = "";
    int operator_level = INT_MAX;
    m_operation = Null;
    for (int i = 0; i < expression.size(); i++){
        if (expression[i] == '('){
            parenthesis_level ++;
        }
        else if (expression[i] == ')'){
            parenthesis_level --;
        }
        else if (expression[i] == '+'){
            if (parenthesis_level < operator_level){
                left_expr += right_expr;
                right_expr = "";
                operator_level = parenthesis_level;
                m_operation = Addition;
            }
        }
        else if (expression[i] == '-'){
            if (parenthesis_level < operator_level){
                left_expr += right_expr;
                right_expr = "";
                operator_level = parenthesis_level;
                m_operation = Substraction;
            }
        }
        else if (expression[i] == '*'){
            if (parenthesis_level < operator_level){
                left_expr += right_expr;
                right_expr = "";
                operator_level = parenthesis_level;
                m_operation = Multiplication;
            }
        }
        else if (expression[i] == '/'){
            if (parenthesis_level < operator_level){
                left_expr += right_expr;
                right_expr = "";
                operator_level = parenthesis_level;
                m_operation = Division;
            }
        }
        if (expression[i] != ' '){
            right_expr += expression[i];
        }
    }
    if (left_expr.size() > 0){
        while(left_expr[0] == '('){
            left_expr.erase(0,1);
        }
    }
    if (right_expr.size() > 0){
        while(right_expr[right_expr.size() - 1] == ')'){
            right_expr.pop_back();
        }
        if (right_expr[0] == '+' || right_expr[0] == '-' || right_expr[0] == '*' || right_expr[0] == '/' || right_expr[0] == '^'){
            right_expr.erase(0,1);
        }
    }
    if (right_expr == ""){
        if (left_expr[0] >= '0' && left_expr[0] <= '9'){
            m_operation = Constant;
            for (int i = 0; i < left_expr.size(); i++){
                if (left_expr[i] >= '0' && left_expr[i] <= '9'){
                    m_value *= 10;
                    m_value += left_expr[i] - '0';
                }
            }
        }
        else {
            m_operation = Variable;
            for (int i = 0; i < left_expr.size(); i++){
                if (left_expr[i] >= 'a' && left_expr[i] <= 'z'){
                    m_variable += left_expr[i];
                }
            }
            bool var_in_list = false;
            for (int i = 0; i < variables->size(); i++){
                if ((*variables)[i] == m_variable){
                    var_in_list = true;
                    m_value = i;
                }
            }
            if (!var_in_list){
                m_value = variables->size();
                variables->push_back(m_variable);
            }
        }
    }
    else if (left_expr == ""){
        if (right_expr[0] >= '0' && right_expr[0] <= '9'){
            m_operation = Constant;
            for (int i = 0; i < right_expr.size(); i++){
                if (right_expr[i] >= '0' && right_expr[i] <= '9'){
                    m_value *= 10;
                    m_value += right_expr[i] - '0';
                }
            }
        }
        else {
            m_operation = Variable;
            for (int i = 0; i < right_expr.size(); i++){
                if (right_expr[i] >= 'a' && right_expr[i] <= 'z'){
                    m_variable += right_expr[i];
                }
            }
            bool var_in_list = false;
            for (int i = 0; i < variables->size(); i++){
                if ((*variables)[i] == m_variable){
                    var_in_list = true;
                    m_value = i;
                }
            }
            if (!var_in_list){
                m_value = variables->size();
                variables->push_back(m_variable);
            }
        }
    }
    else {
        m_right_member = new Function(right_expr, m_variables);
        m_left_member = new Function(left_expr, m_variables);
    }
}

Function::Function(std::string expression){
    m_variables = new std::vector<std::string>;
    m_var_host = true;
    Function(expression, m_variables);

    for (int i = 0; i < m_variables->size(); i++){
        std::cout << "Var " << i << " : " << (*m_variables)[i] << std::endl;
    }
}


Function::~Function(){
    if (m_left_member != nullptr)
        delete m_left_member;
    if (m_right_member != nullptr)
        delete m_right_member;
    if (m_var_host){
        delete m_variables;
    }
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

        default :
            return 0;
    }
}