
/*
2. Stwórz odpowiednie funktory Variable oraz Constant, które mogą być używane
jako argumenty funkcji integrate:  
    Variable x;  
    integrate(x,0,1,0.001); 

    integrate(Constant(1.0),0,1,0.001);
*/

#include <iostream>
#include <cmath>


template <typename F> double integrate(F f, double min, double max, double ds) {
    double integral {0.0};
    for (double x = min; x < max; x += ds) {
        integral += f(x);
    }
    return integral*ds;
};

class Variable {
public:
    double operator()(double x) { return x; }
};

class Constant {
private:
    double _c;

public:
    Constant(double c) : _c(c) { }
    double operator()(double x) { return _c; }
};


int main()
{
    Variable x;
    std::cout << integrate(x, 0, 1, 0.001) << std::endl;

    std::cout << integrate(Constant(1.0), 0, 1, 0.001) << std::endl;


    return 0;
}