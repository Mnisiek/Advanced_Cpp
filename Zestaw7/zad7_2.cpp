
/*
2. Zaimplementuj szablon Pow<N,M> obliczający N^M
*/

#include <iostream>

// szablony funkcji nie pozwalają na częściową specjalizację
// dlatego używamy szablonu klasy (struktury)
template <int N, int M> struct Pow {
    static constexpr int result = (N * Pow<N, M-1>::result);
};

template <int N> struct Pow<N, 0> {
    static constexpr int result = 1;
};


int main()
{
    std::cout << Pow<2, 5>::result << std::endl;

    return 0;
}
