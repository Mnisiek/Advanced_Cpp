
/*
3. Zaimplementuj szablon klasy Is_convertible, za pomocą którego
możliwe jest stwierdzenie, czy jeden z typów można rzutować na drugi.
*/

#include <vector>
#include <deque>
#include <iostream>

using namespace std;

template <typename T, typename U> class Is_convertible {
typedef char one;
typedef struct { char c[2]; } two;
// tym razem korzystamy ze zwykłych przeciążonych funkcji
static one test(U);
static two test(...);
static T makeT();

public:
    static constexpr bool yes = sizeof(test(makeT())) == sizeof(one);
    static constexpr bool same_type = false;
};

template <typename T> 
class Is_convertible<T, T> {
public:
    static constexpr bool yes = true;
    static constexpr bool same_type = true;
};

int main() {

    cout << Is_convertible<int, double>::yes << endl;
    cout << Is_convertible<double, int>::yes << endl;
    cout << Is_convertible<double, int>::same_type << endl;

    cout << Is_convertible<size_t, unsigned int>::same_type << endl;
    cout << Is_convertible<std::vector<double>::value_type, double>::same_type << endl;
    cout << Is_convertible<std::vector<double>::iterator, double *>::same_type << endl;

  return 0;
}
