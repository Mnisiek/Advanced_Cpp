
/*
4. Napisz szablon generujący pierwsze N wyrazów rozwinięcia funkcji sin(x)
*/

// #include <iostream>

// template <int x> constexpr int silnia() {
//     return (x * silnia<x-1>());
// }

// template <> constexpr int silnia<0>() {
//     return 1;
// }


// template <int N, int M> struct Pow {
//     static constexpr int result = (Pow<N * N, M / 2>::result * (M % 2 ? N : 1));
// };

// template <int N> struct Pow<N, 0> {
//     static constexpr int result = 1;
// };


// template <int x, int N> struct sinus {
//     static constexpr double result = ((Pow<-1, N>::result) / (silnia<2*N+1>()) * (Pow<x, 2*N+1>::result)) + sinus<x, N-1>::result;
// };

// template <int x> struct sinus<x, 0> {
//     static constexpr double result = x;
// };

// template <int x, int N> struct print_sin_series {
//     static void print() {
//         std::cout << "sinus(" << x << ", " << N << ") = " << sinus<x, N>::result << std::endl;
//         print_sin_series<x, N - 1>::print();
//     }
// };

// template <int x> struct print_sin_series<x, 0> {
//     static void print() {
//         std::cout << "sinus(" << x << ", " << 0 << ") = " << sinus<x, 0>::result << std::endl;
//     }
// };


// int main() {
//     constexpr int x = 0.5;
//     constexpr int N = 5;

//     // Obliczanie kolejnych wyrazów rozwinięcia funkcji sinus
//     print_sin_series<x, N>::print();

//     return 0;
// }