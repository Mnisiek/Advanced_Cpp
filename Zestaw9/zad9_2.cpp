
/*
2. Sprawdź czy wielkość inteligentnego wskaźnika różni się
od wielkości zwykłego wskaźnika.
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

            std::cout << "Rozmiar Cow*: " << sizeof(Cow*) << ", rozmiar unique_ptr<Cow>: " 
            << sizeof(cow1) << std::endl;
            std::cout << "Rozmiar Cow*: " << sizeof(Cow*) << ", rozmiar shared_ptr<Cow>: " 
            << sizeof(cow2) << std::endl;
        }
        // cow1->makeSound();
        cow2->makeSound();
    }

    return 0;
}