
/*
6.	Jakie jest działanie std::weak_ptr ? Przedstaw przykład użycia.
*/

/*
std::weak_ptr działa podobnie do std::shared_ptr - umożliwia kopiowanie,
ale jednocześnie nie zwiększa licznika aktywnych referencji. Pozwalana śledzenie,
czy zaalokowana wcześniej pamięć na stercie nie została już zwolniona.
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
        std::weak_ptr<Cow> weakCow;
        {
            std::cout << "Reference count: " << weakCow.use_count() << std::endl;
            std::shared_ptr<Cow> sharedCow = std::make_shared<Cow>();
            weakCow = sharedCow;

            weakCow.expired() ? std::cout << "Expired" << std::endl :
                std::cout << "Not expired" << std::endl;

            std::cout << "Reference count: " << weakCow.use_count() << std::endl;
            sharedCow->makeSound();
        }

        weakCow.expired() ? std::cout << "Expired" << std::endl :
            std::cout << "Not expired" << std::endl;
    }

    return 0;
}