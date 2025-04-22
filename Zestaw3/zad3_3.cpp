/*
3. W przeciwieństwie do szablonów funkcji, szablony klas nie mogą być 
przeciążane, a jedynie specjalizowane. Oznacza to, że w programie może 
istnieć tylko jeden szablon podstawowy o danej nazwie.
Proszę zaimplementować specjalizację częściową, która jest dozwolona 
tylko dla szablonów klas, dla podanych podzbiorów parametrów.
*/

#include<iostream>

using namespace std;

template <typename T, int N = 100> class Stack {
public:
    Stack() { cerr << "T,N" << endl; };
};

template <typename T> class Stack<T, 650>     {
public:
    Stack() { cerr << "T,650" << endl; };
};

template <typename T, int N> class Stack<T*, N>      {
public:
    Stack() { cerr << "T*,N" << endl; };
};
template <int N> class Stack<double, N> {
public:
    Stack() { cerr << "double,N" << endl; };
};

template <int N> class Stack<int *, N> {
public:
    Stack() { cerr << "int *,N" << endl; };
};

template <> class Stack<double, 650> {
public:
    Stack() { cerr << "double,650" << endl; };
};

template<> class Stack<double*, 44> {
public:
    Stack() { cerr << "double *,44" << endl; };
};


int main()
{
    Stack<int> s1;

    return 0;
}