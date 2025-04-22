
/*
1. Zaimplementuj szablon is_class służący do sprawdzania, czy dany typ jest klasą.
*/

#include <vector>
#include <iostream>

template <typename T> class Is_class {
// najpierw definiujemy dwa typy różniące sie rozmiarem
typedef char one;
typedef struct { char c[2]; } two;
// teraz potrzebne bedą dwa przeładowane szablony
template<typename U> static one test(int U::*); 
template<typename U> static two test(...);

/* to który szablon został wybrany sprawdzamy poprzez 
   sprawdzenie rozmiaru zwracanego typu */
public:
    enum { yes = (sizeof(test<T>(0)) == sizeof(one)) };
};


struct X { };

int main() {
    // w c++17 można skorzystać z funkcji biblioteki standardowej
    std::cout << std::is_class<X>::value << std::endl;
    if (Is_class<int>::yes) {
        std::cout << "Typ <int> jest klasa" << std::endl;
    } else {
        std::cout << "Typ <int> nie jest klasa" << std::endl;
    }

    if (Is_class<X>::yes) {
        std::cout << "Typ <X> jest klasa" << std::endl;
    } else {
        std::cout << "Typ <X> nie jest klasa" << std::endl;
    }

    if (Is_class<std::vector<double>>::yes) {
        std::cout << "Typ <std::vector<double>> jest klasa" << std::endl;
    } else {
        std::cout << "Typ <std::vector<double>> nie jest klasa" << std::endl;
    }

    return 0;
}
