
/*
6. Rozszerz powyższy szablon tak, aby również typ elementów wektora był parametrem szablonu:

template<size_t N, typename T> T dot(T *x, T *y);
*/

#include <iostream>


template <size_t N, typename T> T dot(T *x, T *y) {
    T result = T();

    for (int i = 0; i < N; ++i) {
        result += x[i] * y[i];
    }

    return result;
}


int main()
{
    int vec1[] = {1, 2, 3};
    int vec2[] = {4, 5, 6};
    std::cout << dot<3, int>(vec1, vec2) << std::endl;

    return 0;
}
