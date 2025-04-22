/*
2. Na przykładzie szablonu funkcji convert pokazać, że jest możliwe 
zdefiniowanie dwóch funkcji o tej samej nazwie i argumentach wywołania, 
różniących się tylko zwracanym typem.
*/

#include <iostream>

template <typename T, typename U> T convert(U arg)
{
    return static_cast<T>(arg);
}

// używamy specjalizacji dla szablonu funkcji convert
template <> int convert<int, double>(double arg)
{
    return static_cast<int>(arg);
}

template <> double convert<double, double>(double arg)
{
    return static_cast<double>(arg);
}


int main()
{
    std::cout << convert<int>(7.23) << std::endl;
    std::cout << convert<double>(7.23) << std::endl;

    return 0;
}
