
#include <iostream>

template <typename T, typename U>
T convert(U arg) {
    // return (T) arg;
    
    return static_cast<T>(arg);
    // C++ style casts are checked by the compiler.
    // C style casts aren't and can fail at runtime.
    // Source: Stackoverflow
}

int main()
{
    std::cout << convert<char>(65) << std::endl;
    std::cout << convert<int>(4.7) << std::endl;
}