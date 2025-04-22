
/*
4. Zdefiniuj szablon Strip, który jako funkcja typów dokonuje operacji usunięcia jednego
lub obydwu kwalifikatorów (const oraz &) i uzyskanie gołego typu podstawowego.
*/

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

// Szablon usuwajacy kwalifikatory
template <typename T> struct Strip {
    typedef T arg_t;
    typedef T striped_t;
    typedef T base_t;
    typedef const T const_type;

    typedef T& ref_type;
    typedef T& ref_base_type;
    typedef const T& const_ref_type;
};

template <typename T> struct Strip <T const> {
    typedef const T arg_t;
    typedef T striped_t;
    typedef typename Strip<T>::base_t base_t;
    typedef T const const_type;

    typedef T const& ref_type;
    typedef T& ref_base_type;
    typedef T const& const_ref_type;
};

template<typename T> struct Strip<T&> {
    typedef T& arg_t;
    typedef T striped_t;
    typedef typename Strip<T>::base_t base_t;
    typedef base_t const const_type;

    typedef T ref_type;
    typedef base_t& ref_base_type;
    typedef base_t const & const_ref_type;
};


int main() {
    cout << Is_convertible<Strip<const int&>::base_t, int>::same_type << endl; 
    cout << Is_convertible<Strip<const int&>::const_ref_type, const int>::same_type << endl;

    return 0;
}
