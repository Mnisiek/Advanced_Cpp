
#include <iostream>

// Szablon stosu z wykładu
template <typename T>
class Stack {
public:
    static const size_t N = 100;
    typedef T value_type;
private:
    T _rep[N];
    size_t _top;
public:
    Stack():_top(0) { };
    void push(T val) { _rep[_top++] = val; }
    T pop() { return _rep[--_top]; }
    bool is_empty() {return (_top == 0);} 
};

template <typename Stack>
typename Stack::value_type suma(Stack stack) {
    typename Stack::value_type result = {};

    while (!stack.is_empty()) {
        result += stack.pop();
    }
    return result;
}

int main()
{
    Stack<int> stack1;
    stack1.push(3);
    stack1.push(5);
    stack1.push(1);

    std::cout << suma(stack1) << std::endl;
}
