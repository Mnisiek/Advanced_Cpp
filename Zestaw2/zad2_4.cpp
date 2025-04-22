/*
4. Zaimplementuj klasę (funktor typu generator) SeqenceGen, przy wykorzystaniu
której wypełnij za pomocą algorytmu generate_n wektor sekwencją 20 pierwszych
nieparzystych liczb całkowitych. Znajdź element większy od 4 przy wykorzystaniu
adaptera bind oraz algorytmu find_if.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using vIntIter = std::vector<int>::iterator;

template <typename T> class SequenceGen {
    private:
    T m_start;
    T m_step;

    public:
    SequenceGen(T start = T(), T step = 1) : m_start(start), m_step(step) { }
    T operator()() { T tmp = m_start; m_start += m_step; return tmp; }
};


int main()
{
    std::vector<int> vec(20);
    std::generate_n(vec.begin(), 20, SequenceGen<int>(1, 2));
    // for (int element : vec) {
    //     std::cout << element << ", ";
    // }
    // std::cout << std::endl;
    
    
    vIntIter it = std::find_if(vec.begin(), vec.end(), std::bind(
        std::greater<int>(), std::placeholders::_1, 4));

    if (it != vec.end()) {
        std::cout << *it << std::endl;
    } else {
        std::cout << "Nie znaleziono zadanego elementu" << std::endl;
    }

    return 0;
}