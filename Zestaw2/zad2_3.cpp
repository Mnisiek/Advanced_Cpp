/*
3. Zaimplementuj szablon funkcji accumulate, której pierwszy i drugi argument są 
iteratorami dowolnego kontenera STL. Funkcja ma za zadanie wyliczać sumę wszystkich
elementów w przedziale podanych iteratorów.
*/

#include <iostream>
#include <set>

typedef std::set<int>::const_iterator sIntIter;

template <typename Iterator, typename T>
T accumulate(Iterator first, Iterator last) {
    T result = {};
    while (first != last) {
        result += *first;
        ++first;
    }
    return result;
}


int main()
{
    std::set<int> s1;
    s1.insert(2);
    s1.insert(5);
    s1.insert(7);
    s1.insert(2);
    s1.insert(1);

    std::cout << accumulate<sIntIter, int>(s1.begin(), s1.end()) << std::endl;
    // set jest posortowany
    std::cout << accumulate<sIntIter, int>(s1.begin(), ++++s1.begin()) << std::endl;

    return 0;
}