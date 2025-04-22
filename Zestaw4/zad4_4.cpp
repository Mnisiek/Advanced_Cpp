
/*
4. Uogólnić funkcję sum, aby działała nie tylko ze wskaźnikami, ale i iteratorami. Widać, że tu użycie klas cech jest już niezbędne, musimy bowiem dowiedzieć się na obiekty jakiego typu wskazuje iterator. Nie można do tego celu użyć typów stowarzyszonych IT::value_type, bo jako iterator może zostać podstawiony zwykły wskaźnik. Dlatego w STL istnieje klasa iterator_traits, definiująca podstawowe typy dla każdego rodzaju iteratora. Korzystając z tej klasy zdefiniuj ogólny szablon funkcji sum.
*/

#include <iostream>
#include <string.h>
using namespace std;

template <typename T> struct sum_traits;

template<> struct sum_traits<char> {
typedef int sum_type;
static sum_type zero() {return 0;}
};
template<> struct sum_traits<int> {
typedef long int sum_type;
static sum_type zero() {return 0L;}
};
template<> struct sum_traits<long> {
typedef long long sum_type;
static sum_type zero() {return 0LL;}
};
template<> struct sum_traits<float> {
typedef double sum_type;
static sum_type zero() {return 0.0;}
};
template<> struct sum_traits<double> {
typedef long double sum_type;
static sum_type zero() {return 0.0L;}
};

template <typename IT>
typename sum_traits<typename iterator_traits<IT>::value_type>::sum_type 
sum(IT beg, IT end) {
    typedef typename iterator_traits<IT>::value_type value_type;
    typedef typename sum_traits<value_type>::sum_type sum_type;
    sum_type total = sum_traits<value_type>::zero(); 
    while (beg != end) { 
        total += *beg; 
        beg++; 
    } 
    return total;
}

template <typename T> 
typename sum_traits<T>::sum_type sum(T *beg, T *end) { 
    return sum<T*>(beg, end);
}


int main() {
    char name[] = "@ @ @";
    int length = strlen(name);

    cout << (int)sum(name, &name[length]) << endl;
    cout << (int)sum<char>(name, &name[length]) << endl;

    // long long long_arr[] = {1, 2, 3, 4, 5};
    // cout << sum<long>(long_arr, long_arr + 5) << endl;

    double double_arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int double_length = sizeof(double_arr) / sizeof(double_arr[0]);
    std::cout << "\nSuma[double]: " << sum(double_arr, double_arr + double_length) << "\n";
}