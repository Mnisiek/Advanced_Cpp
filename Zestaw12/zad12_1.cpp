
/*
Opisz funkcję oraz zastosowanie wzorca projektowego Singleton, a następnie przedstaw
jego implementację w języku C++. W swoim opisie uwzględnij wyjaśnienie, dlaczego
wzorzec ten jest użyteczny, jakie problemy rozwiązuje oraz zaprezentuj kompletny
przykład kodu, który ilustruje jego działanie i sposób użycia w praktycznej aplikacji.
*/


// Singleton jest wzorcem projektowym, który pozwala zapewnić istnienie wyłącznie
// jednej instancji danej klasy. Ponadto daje globalny punkt dostępowy do tejże instancji.
// Singleton jest często używany do zarządzania zasobami, takimi jak połączenia z
// bazą danych, menedżery logowania, konfiguracje aplikacji itp.

#include <iostream>


class Cow {
private:
    Cow() : name("Mućka"), age(7) {}
    static Cow* cow_;
    std::string name;
    int age;

public:
    Cow(Cow &other) = delete;
    void operator=(const Cow &) = delete;
    static Cow* getInstance();
    void makeSound() {
        std::cout << "Muuu" << std::endl;
    }
    std::string getName() const { return name; }
    int getAge() const { return age; }
};

Cow* Cow::getInstance() {
    if (cow_ == nullptr) {
        cow_ = new Cow();
    }
    return cow_;
}

Cow* Cow::cow_ = nullptr;


int main() {
    Cow* cow1 = Cow::getInstance();
    cow1->makeSound();
    std::cout << "Name: " << cow1->getName() << ", age: " << cow1->getAge() << std::endl;

    Cow* cow2 = Cow::getInstance();
    cow2->makeSound();
    std::cout << "Name: " << cow2->getName() << ", age: " << cow2->getAge() << std::endl;

    if (cow1 == cow2) {
        std::cout << "cow1 i cow2 wskazują na tę samą instancję." << std::endl;
    }

    return 0;
}