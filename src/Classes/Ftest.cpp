#include "Ftest.hpp"
#include <stdio.h>


Ftest::Ftest(char* name) : m_name(name) {
    printf("\n%c\n", m_name);
}



float Ftest::image(std::vector<float> x) {
            return 2*x[0] - 2;
        }