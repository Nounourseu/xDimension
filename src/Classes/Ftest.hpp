#ifndef FTEST_HPP
#define FTEST_HPP
#include <vector>

class Ftest {
    public:
        Ftest(char name[20]);
        float image(std::vector<float> x);
    
    protected:
        char* m_name;
};


#endif