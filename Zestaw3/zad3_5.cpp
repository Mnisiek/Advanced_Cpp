/*
5. Zapoznaj się z rodziną funktorów porównujących, do której należą
np. less<>(), greater<>(), less_equal<>(), greater_equal<>().
Przypomnij sobie pojemnik std::set. Następnie napisz programik
korzystający ze zbioru liczb posortowanego odwrotnie (czyli malejąco).
*/

#include <iostream>
#include <set>
#include <functional>


int main()
{
    // deklaracja zbioru posortowanego malejąco
    std::set<int, std::greater<int>> s1;
    s1.insert(3);
    s1.insert(5);
    s1.insert(1);
    s1.insert(7);
    s1.insert(9);
    s1.insert(15);
    s1.insert(2);
    
    for (const auto& element : s1) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}