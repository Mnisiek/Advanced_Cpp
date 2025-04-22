
/*
5. Zapoznaj się z plikiem kategorie.cpp.(http://wazniak.mimuw.edu.pl/images/c/c4/Kategorie.cpp). Jest w nim przedstawiony sposób selekcji jednej spośród kilku implementacji algorytmu na podstawie możliwości oferowanych przez przekazany iterator; w tym konkretnym przykładzie rozróżniamy dwie grupy: iteratory o swobodnym dostępie oraz wszystkie inne. Rozszerz kod tak, aby wybierana była jedna z trzech możliwości: swobodny dostęp, dwukierunkowe, gorsze niż dwukierunkowe.
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <list>
#include <set>
#include <queue>
using std::list;

#include <iterator>
using std::iterator_traits;
using std::forward_iterator_tag;
using std::bidirectional_iterator_tag;
using std::random_access_iterator_tag;


template <typename Iter>
int operacja_impl(Iter i, forward_iterator_tag)
{
    std::cout << "Iterator jednokierunkowy.\n";
    return 2;
}

template <typename Iter>
int operacja_impl(Iter i, bidirectional_iterator_tag)
{
    std::cout << "Iterator dwukierunkowy.\n";
    return 3;
}

template <typename Iter>
int operacja_impl(Iter i, random_access_iterator_tag)
{
    std::cout << "Iterator o swobodnym dostepie.\n";
    return 4;
}

template <typename Iter>
inline int operacja(Iter i)
{
    return operacja_impl(i,
            typename iterator_traits<Iter>::iterator_category());
}


int main()
{
    list<int> l;
    operacja(l.begin());

    int t[3];
    operacja(t);

    std::set<int> s = {1, 2, 3};
    operacja(s.begin());

    std::cout << "\n";
    
    std::queue<int> q;
    operacja_impl(q, std::forward_iterator_tag());

    return 0;
}


