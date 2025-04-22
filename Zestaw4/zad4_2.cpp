
/*
2. Rozwiązać za pomocą klas cech również problem inicjalizacji zmiennej total.
*/

#include <iostream>
#include <string.h>
using namespace std;

template <typename T> struct sum_traits;

template<>  struct sum_traits<char> {
typedef int sum_type;
static sum_type zero() {return 0;}
};
template<>  struct sum_traits<int> {
typedef long int sum_type;
static sum_type zero() {return 0L;}
};
template<>  struct sum_traits<long> {
typedef long long sum_type;
static sum_type zero() {return 0LL;}
};
template<>  struct sum_traits<float> {
typedef double sum_type;
static sum_type zero() {return 0.0;}
};
template<>  struct sum_traits<double> {
typedef long double sum_type;
static sum_type zero() {return 0.0L;}
};

template<typename T> 
typename sum_traits<T>::sum_type sum(T *beg,T *end) { 
    typedef typename sum_traits<T>::sum_type sum_type;
    sum_type total = sum_traits<T>::zero();
    while (beg != end ) { 
        total += *beg; beg++; 
    } 
        return total;
};


int main() 
{
    char name[] = "@ @ @";
    int length = strlen(name);

    cout << sum(name,&name[length]) << endl;

    return 0;
}

