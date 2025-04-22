
/*
7. Opisz sposób wykorzystania szablonów wyrażeń wektorowych (na podstawie
przygotowanego wcześniej kodu) do efektywnego obliczenia wyrażeń wektorowych np.  

Vector v1(100,1);  
Vector v2(100,2);  
Vector res(100);  

res = 1.2*v1+v1*v2+v2*0.5;
*/

// ---------------------------------------------------------------------------------------------------------------

#include <vector>
using namespace std;


// Implementacja operatora dodawania dla dwóch wektorów:
    template<typename T> vector<T> operator+(const vector<T> &lhs, const vector<T> &rhs) {
    vector<T> res(lhs) ;
    for (size_t i = 0; i < rhs.size(); ++i) {
        res[i] += rhs[i];
    }
    return res;
    } 

// ---------------------------------------------------------------------------------------------------------------

// Implementacja operatora mnożenia dla dwóch wektorów:
    template<typename T> vector<T> operator*(const vector<T> &lhs, const vector<T> &rhs) {
    vector<T> res(lhs) ;
    for(size_t i = 0; i < rhs.size(); ++i) {
        res[i] *= rhs[i];
    }
    return res;
    }

// ---------------------------------------------------------------------------------------------------------------

// Implementacja operatora mnożenia wektora przez skalar:
template<typename T> vector<T> operator*(const double scalar, const vector<T> &rhs) {
    vector<T> res(rhs) ;
    for(size_t i = 0; i < rhs.size(); ++i) {
        res[i] *= scalar;
    }
    return res;
}

// Implementacja operatora mnożenia wektora przez skalar:
template<typename T> vector<T> operator*(const vector<T> &lhs, const double scalar) {
    vector<T> res(lhs) ;
    for(size_t i = 0; i < lhs.size(); ++i) {
        res[i] *= scalar;
    }
    return res;
}

// ---------------------------------------------------------------------------------------------------------------

// Kod:
int main() {
    vector<double> v1(100,1);
    vector<double> v2(100,2);
    vector<double> res(100);
#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedValue"
    res = 1.2*v1+v1*v2+v2*0.5;
#pragma clang diagnostic pop

// ---------------------------------------------------------------------------------------------------------------

// Jeśli popatrzymy na definicję operatorów, to zauważymy, że ta linijka w rzeczywistości generuje:
    vector<double> tmp1(100);
    tmp1=0.5*v2;

    vector<double> tmp2(100);
    tmp2=v1*v2;

    vector<double> tmp3(100);
    tmp3=tmp1+tmp2;

    vector<double> tmp4(100);
    tmp4=1.2*v1;

    vector<double> tmp5(100);
    tmp5=tmp3+tmp4;

    res=tmp5;

// Tworzymy 5 tymczasowych wektorów (przydzielając na nie pamięć) i 6 razy kopiujemy wektory.
// Pisząc ten sam kod ręcznie, napisalibyśmy:
    for(int i = 0; i < 100; i++) {
        res[i] = 1.2 * v1[i] + v1[i] * v2[i] + v2[i] * 0.5;
    }

// Niepotrzebny jest żaden obiekt tymczasowy i tylko jedno kopiowanie.
// Ponadto możemy liczyć na to, że kompilator lepiej zoptymalizuje tak prosty kod np. eliminując jedno mnożenie:
    for(int i = 0; i < 100; i++) {
        res[i] = v1[i] * (1.2 + v2[i]) + v2[i] * 0.5;
    }
}

// Te dodatkowe niepotrzebne kopiowania i tymczasowe obiekty stanowią duży narzut (czasowy i pamięciowy).

// ---------------------------------------------------------------------------------------------------------------

// Sposób wykorzystania szablonów wyrażeń wektorowych

// Zaczynamy więc od zdefiniowania nowej klasy Vector. Nie możemy użyć std::vector bezpośrednio,
// ponieważ potrzebujemy przeładować operator przypisania, ale możemy wykorzystać std::vector
// do implementacji naszej klasy np. korzystając z dziedziczenia. Musimy wtedy także zdefiniować
// własne konstruktory. Definiujemy też nowy operator przypisania. Następnie definiujemy wyrażenie
// reprezentujace sumę dwóch wektorów.

// ---------------------------------------------------------------------------------------------------------------