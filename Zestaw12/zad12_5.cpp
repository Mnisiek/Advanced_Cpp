
/*
Opisz funkcję oraz zastosowanie wzorca projektowego Visitor (Odwiedzający),
a następnie przedstaw jego implementację w języku C++. W swoim opisie uwzględnij,
jak wzorzec Visitor umożliwia dodawanie nowych operacji do klas bez modyfikowania
ich kodu, poprzez separację algorytmu od struktury obiektów. Zaprezentuj kompletny
przykład kodu, który ilustruje jego działanie i sposób użycia w praktycznej aplikacji.
*/

// Visitor to wzorec projektowy, który pozwala oddzielić algorytmy od obiektów
// na których pracują. Umożliwia dodanie nowych operacji do klas bez modyfikowania
// ich kodu. Jest to przydatne, gdy mamy hierarchię klas i chcemy wykonywać różne
// operacje na obiektach, ale nie chcemy lub nie możemy modyfikować danych klas.


#include <iostream>
#include <string>

class Cow;

// Interfejs odwiedzającego
class Visitor {
public:
    virtual void visit(Cow* cow) = 0;
};

// Klasa odwiedzana
class Cow {
private:
    std::string name;
    int age;

public:
    Cow(std::string name, int age) : name(name), age(age) {}

    std::string getName() const { return name; }
    int getAge() const { return age; }
    void makeSound() {
        std::cout << "Muuu" << std::endl;
    }
    void accept(Visitor* visitor) {
        visitor->visit(this);
    }
};

// Konkretna klasa odwiedzająca
class SoundVisitor : public Visitor {
public:
    void visit(Cow* cow) override {
        std::cout << cow->getName() << " says ";
        cow->makeSound();
    }
};

class AgeVisitor : public Visitor {
public:
    void visit(Cow* cow) override {
        std::cout << cow->getName() << " is " << cow->getAge() << " years old." << std::endl;
    }
};

int main() {
    Cow* cow = new Cow("Bella", 5);

    SoundVisitor* soundVisitor = new SoundVisitor();
    AgeVisitor* ageVisitor = new AgeVisitor();

    cow->accept(soundVisitor); // Bella says Muuu!
    cow->accept(ageVisitor);   // Bella is 5 years old.

    delete cow;
    delete soundVisitor;
    delete ageVisitor;

    return 0;
}
