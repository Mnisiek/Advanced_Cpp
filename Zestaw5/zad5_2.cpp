
/*
2. Napisz szablon, który sprawdza czy jego parametr posiada typ stowarzyszony value_type,np.:
has_value_type<std::vector<int>>::yes powinno mieć wartość true,
a has_value_type<int>::yes wartość false.
*/

#include <vector>
#include <iostream>

template <typename T> class has_value_type {
typedef char yes;
typedef struct { char c[2]; } no;

template<typename U> static yes test(typename U::value_type*); 
template<typename U> static no test(...);

public:
    static constexpr bool value = sizeof(test<T>(nullptr)) == sizeof(yes);
};


struct X { };

int main() {
    // void_t w c++17
    //template <typename T> struct std::void_t<typename T::value_type>>
    if (has_value_type<int>::value) {
        std::cout << "Typ <int> posiada typ stowarzyszony" << std::endl;
    } else {
        std::cout << "Typ <int> nie posiada typu stowarzyszonego" << std::endl;
    }

    if (has_value_type<X>::value) {
        std::cout << "Typ <X> posiada typ stowarzyszony" << std::endl;
    } else {
        std::cout << "Typ <X> nie posiada typu stowarzyszonego" << std::endl;
    }

    if (has_value_type<std::vector<double>>::value) {
        std::cout << "Typ <std::vector<double>> posiada typ stowarzyszony" << std::endl;
    } else {
        std::cout << "Typ <std::vector<double>> nie posiada typu stowarzyszonego" << std::endl;
    }

    return 0;
}