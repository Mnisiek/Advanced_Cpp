
#include <iostream>

template <int N, typename T>
T dot_product(T* vec1, T* vec2) {
    T result {};
    for (int i = 0; i < N; ++i) {
        result += vec1[i] * vec2[i];
    }
    return result;
}

int main()
{
    int vec[] = {1, 2, 3};
    std::cout << dot_product<3>(vec, vec) << std::endl;
}