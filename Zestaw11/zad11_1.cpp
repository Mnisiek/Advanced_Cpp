
/*
1. Podaj przykłady wykorzystania konceptu std::integral tak, aby szablon funkcji
działał poprawnie tylko dla typów zmiennych spełniających wymagania tego konceptu
(np. funkcja gcd – największy wspólny dzielnik). 
*/


#include <iostream>
#include <concepts>


template<typename T>
requires std::integral<T>
auto gcd(T a, T b) {
    if ( b == 0 ) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}


int main()
{
    std::cout << "gcd(18, 56)= " << gcd(18, 56) << std::endl;

    return 0;
}
