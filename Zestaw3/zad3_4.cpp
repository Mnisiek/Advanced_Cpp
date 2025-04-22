/*
4. Zaimplementować szablon klasy Stack wraz z jej specjalizacjami tak,
aby „działała” ze zwykłymi tablicami oraz kontenerami STL.
*/

#include <deque>
#include <iostream>

template <typename T, int N = 100, typename R = T*> class Stack;

template <typename T, int N> class Stack<T, N, T*> {
    T _rep[N];
    unsigned int _top;
public:
    Stack(): _top(0) { };
    void push(T e) { _rep[_top++] = e; }
    T pop() { return _rep[--_top]; }
};

template <typename T, int N, template <typename E, typename Allocator = std::allocator<E>> class Sequence> 
    class Stack<T,N,Sequence<T>> {
    Sequence<T> _rep;
public:
    void push(T e) { _rep.push_back(e); };
    T pop() { T top = _rep.top(); _rep.pop_back(); return top; }
    bool is_empty() const { return _rep.empty(); }
};

template <typename T, int N, template <typename E> class Sequence> 
    class Stack<T,N,Sequence<T>> {
    Sequence<T> _rep;
public:
    void push(T e) { _rep.push_back(e); };
    T pop() { T top = _rep.top(); _rep.pop_back(); return top; }
    bool is_empty() const { return _rep.empty(); }
};


int main() 
{
    Stack<int, 100, int*> s_table;
    Stack<int, 100> s_default;
    Stack<int, 10, std::deque<int>> s_container;
    // s_container.push(10);
    // std::cout << s_container.pop() << std::endl;
    std::cout << "fdsfjdsfdjf" << std::endl;
    


  return 0;
}

