
#include <iostream>

template <typename T>
T maksimum(T x, T y) {
    return (x < y)? y: x;
}

int main() {
    std::cout << maksimum<double>(3.5, 3.2) << std::endl;
}