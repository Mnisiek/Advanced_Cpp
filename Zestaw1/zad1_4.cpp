
#include <iostream>

template <int N>
class Cube {
    public:
    void volume() {
        std::cout << N*N*N << std::endl;
    }
};

// klasa C jest szablonem parametrów szablonu
// funkcja consecutiveIntegers korzysta z tego szablonu parametrów
template <template <int N> class C, int K>
void f(C<K> obj)
{
    obj.volume();
    std:: cout << K << std::endl;
}

int main()
{
    Cube<3> c1;
    f(c1);
}
