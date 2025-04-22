
/*
1. Napisz szablon funkcji lub klasy wyliczający funkcję silnia
*/

#include <iostream>

// wykorzysujemy szablon funkcji
template <int x> constexpr int silnia() {
    return (x * silnia<x-1>());
}

template <> constexpr int silnia<0>() {
    return 1;
}


int main()
{
    std::cout << silnia<10>() << std::endl;

    return 0;
}
