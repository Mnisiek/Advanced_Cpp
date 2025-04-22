
/*
Zaimplementuj rozszerzenie klasy Variable dla przypadku funktorów dwóch zmiennych,
tj. klasy First oraz Second. Podaj przykład całkowania prostej funkcji np. x + y.
*/

#include <iostream>


template <typename F>
double integrate(F f, double min1, double max1, double min2, double max2, double ds) {
    double integral {0.0};
    for (double x = min1; x < max1; x += ds) {
        for (double y = min2; y < max2; y += ds) {
            integral += f(x, y);
        }
    }
    return integral*ds*ds;
}

template <typename T>
class First {
public:
    T operator()(T x, T y) { return x; }
};

template <typename T>
class Second {
public:
    T operator()(T x, T y) { return y; }
};


int main()
{
    First<double> x;
    Second<double> y;

    auto f = [](double x, double y) { return x + y; };

    std::cout << integrate(f, 0, 1, 0, 1, 0.001) << std::endl;

    return 0;
}
