/*
1. Podaj implementacje funkcji max dla różnego typu argumentów.
Skorzystaj z możliwości przeciążania i specjalizacji szablonów funkcji.
*/

#include <iostream>
#include <string.h>

using namespace std;


template <typename T> T max(T a, T b)
{
    cerr << "T " << endl;
    return (a>b)? a: b;
}

template <typename T> T max(T *data, int n)
{
    T _max = data[0];
    cerr << "T[]" << endl;
    for(int i = 0; i<n; ++i) {
        if(data[i]>_max) {
            _max=data[i];
        }
    }
    return _max;
}

template <typename T> T* max(T *a, T *b)
{
    cerr << "T*" << endl;
    return ( ((*a)>(*b))? a: b );
}

template <> char* max(char *a, char *b)
{
    cerr << "S1" << endl;
    return (strcmp(a,b) > 0) ?a: b;
}

template<> const char* max(const char *a, const char *b)
{
    cerr << "S2" << endl;
    return (strcmp(a,b) > 0)? a: b;
}


// definiujemy kolejne przeciążenie
template <typename T> const T* max(T *a, const T *b) {
    return ((*a)>(*b))? a: b;
}
// teraz nasza specjalizacja szablonu jest poprawna
template <> const char* max(char *a, const char *b) {
    cerr << "S3" << endl;
    return (strcmp(a,b) > 0)? a: b;
}


int main()
{
    int tab[] = {1, 2, 3, 4, 5};
    std::cout << max<int>(tab, sizeof(tab)/ sizeof(tab[0])) << std::endl;
    
    return 0;
}