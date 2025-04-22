
/*
Opisz funkcję oraz zastosowanie wzorca projektowego Adapter, a następnie przedstaw
jego implementację w języku C++. W swoim opisie uwzględnij, jak wzorzec Adapter
umożliwia współpracę między klasami o niekompatybilnych interfejsach poprzez
przekształcanie jednego interfejsu na inny. Zaprezentuj kompletny przykład kodu,
który ilustruje jego działanie i sposób użycia w praktycznej aplikacji.
*/

// Adapter jest wzorcem projektowym, który pozwala na współdziałanie ze sobą
// obiektów o niekompatybilnych interfejsach przez przekształcanie jednego interfejsu
// na drugi. Adapter działa jako pośrednik, który opakowuje jeden obiekt
// i udostępnia jego funkcjonalności w sposób zgodny z oczekiwaniami innej klasy.
// Adaptery są przydatne, gdy chcesz użyć w programie klasy, która nie spełnia
// wymagań interfejsu innej klasy.


#include <iostream>
#include <string>

class Animal {
public:
    virtual ~Animal() = default;
    virtual void makeSound() const = 0;
    virtual std::string getName() const = 0;
};

class Cow {
private:
    std::string name;

public:
    Cow() : name("Mućka") { }

    void muuu() const {
        std::cout << "Muuu!" << std::endl;
    }
    std::string getName() const { return name; }
};

// Adapter
class CowAdapter : public Animal {
private:
    Cow& cow;
public:
    CowAdapter(Cow& cow) : cow(cow) {}

    void makeSound() const override {
        std::cout << cow.getName() << " robi ";
        cow.muuu();
    }

    std::string getName() const override {
        return cow.getName();
    }
};


int main() {
    Cow cow;
    CowAdapter cowAdapter(cow);

    // Klient używa interfejsu Animal
    Animal* animal = &cowAdapter;
    animal->makeSound();
    std::cout << "Krowa nazywa się: " << cowAdapter.getName() << std::endl;

    return 0;
}
