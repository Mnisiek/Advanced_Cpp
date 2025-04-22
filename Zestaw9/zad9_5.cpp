
/*
5.	Pokaż, że używanie wskaźnika typu shared_ptr zapewnia wywołanie destruktora
w przypadku znikania ostatniego z nich.
*/

#include <iostream>
#include <string>
#include <memory>


class Cow {
private:
    std::string name;
    int age;

public:
    Cow() : name("Mućka"), age(7) {
        std::cout << "created new cow" << std::endl;
    }
    ~Cow() {
        std::cout << "destroyed a cow" << std::endl;
    }
    void makeSound() {
        std::cout << "Muuu" << std::endl;
    }
};


int main()
{
    {
        std::shared_ptr<Cow> cow1;
        {
            std::shared_ptr<Cow> cow2 = std::make_shared<Cow>();
            cow1 = cow2;

            cow2->makeSound();
            cow1->makeSound();
        }
        // cow2->makeSound();
        std::cout << "Out of inner scope" << std::endl;
        cow1->makeSound();
    }

    return 0;
}