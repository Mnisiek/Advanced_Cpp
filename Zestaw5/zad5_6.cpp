
/*
6. Napisz funkcje zwracające: długość listy typów, typ dla określonego indeksu listy typów
oraz taką, która sprawdza czy dany typ jest wymieniony w podanej liście typów.
*/

#include <iostream>
#include <typeinfo>
#include <type_traits>

using namespace std;

// Funkcja zwracająca długość listy typów
template<typename... Types>
constexpr size_t length_of_types_list() {
    return sizeof...(Types);
}

// Funkcja zwracająca typ znajdujący się pod określonym indeksem w liście typów
template<size_t Index, typename... Types>
struct type_at_index_helper;

template<size_t Index, typename T, typename... Types>
struct type_at_index_helper<Index, T, Types...> {
    typedef typename type_at_index_helper<Index - 1, Types...>::type type;
};

template<typename T, typename... Types>
struct type_at_index_helper<0, T, Types...> {
    typedef T type;
};

template<size_t Index, typename... Types>
using type_at_index = typename type_at_index_helper<Index, Types...>::type;

// Funkcja sprawdzająca, czy dany typ jest obecny w podanej liście typów
template<typename T, typename... Types>
constexpr bool is_type_in_list() {
    return std::disjunction<std::is_same<T, Types>...>::value;
}

int main() {
    // Testowanie funkcji length_of_types_list
    cout << "Dlugosc listy typow: " << length_of_types_list<int, double, char>() << endl;

    // Testowanie funkcji type_at_index
    cout << "Typ na indeksie 0: " << typeid(type_at_index<0, int, double, char>).name() << endl;

    // Testowanie funkcji is_type_in_list
    cout << "Czy int jest w liscie typow? " << is_type_in_list<int, double, char, int>() << endl;
    cout << "Czy float jest w liscie typow? " << is_type_in_list<float, int, double, char>() << endl;

    return 0;
}
