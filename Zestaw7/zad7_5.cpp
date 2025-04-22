
/*
5. Napisz szablon generujący funkcję implementującą iloczyn skalarny dwu wektorów.

template<size_t N> double inner(double *x, double *y);
*/

#include <iostream>


template <size_t N> double inner(double *x, double *y) {
    double result = 0.0;

    for (int i = 0; i < N; ++i) {
        result += x[i] * y[i];
    }

    return result;
}


int main()
{
    double vec1[] = {1.0, 2.0, 3.0};
    double vec2[] = {4.0, 5.0, 6.0};
    std::cout << inner<3>(vec1, vec2) << std::endl;

    return 0;
}
