
/*
3. Wymyśl i zaimplementuj jako metaprogram szybszy algorytm funkcji pow(x)
*/

#include <iostream>

// korzystamy z algorytmu szybkiego potęgowania
template <int N, int M> struct Pow {
    // w zależności od tego, czy wykładnik M jest parzysty, mnożymy wynik przez 1 albo N
    static constexpr int result = (Pow<N * N, M / 2>::result * (M % 2 ? N : 1));
};

template <int N> struct Pow<N, 0> {
    static constexpr int result = 1;
};


int main()
{
    std::cout << Pow<2, 15>::result << std::endl;

    return 0;
}
