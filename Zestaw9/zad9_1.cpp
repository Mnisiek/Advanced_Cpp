
/*
1. Objaśnij działanie inteligentnych wskaźników: shared_ptr, unique_ptr
*/

// unique_ptr
/*
Jest to klasa opakowująca zwykły wskaźnik (raw pointer), która
pozwala na tylko jednego właściciela pamięci zaalokowanej na stercie
(w związku z tym nie można kopiować obiektu typu unique_ptr).
Obiekt type unique_ptr znajduje się na stosie, więc pamięć jest
automatycznie zwalniana, kiedy wyjdziemy poza zakres deklaracji.
*/

// shared_ptr
/*
Podobnie jak unique_ptr także jest klasą opakowującą raw pointera,
ale tym razem do kontrolowania zwalniania pamięci korzysta z
licznika referencji (reference counting). Obiekty typu shared_ptr
można kopiować, zwiększając w ten sposób licznik aktywnych referencji.
Pamięć jest automatycznie zwalniania, gdy reference count jest równy
zero, czyli nie żadnej aktywnej refencji do tego obszaru pamięci.
*/

#include <iostream>
#include <string>
#include <memory>


class Cow {
private:
    std::string name;
    int age;

public:
    Cow() : name("Mućka"), age(7) {}
    void makeSound() {
        std::cout << "Muuu" << std::endl;
    }
};


int main()
{
    {    
        std::shared_ptr<Cow> cow2;
        {
            std::unique_ptr<Cow> cow1 = std::make_unique<Cow>();
            std::shared_ptr<Cow> cow3 = std::make_shared<Cow>();
            cow2 = cow3;
        }
        // cow1->makeSound();
        cow2->makeSound();
    }

    return 0;
}