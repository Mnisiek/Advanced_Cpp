
/*
Opisz funkcję oraz zastosowanie wzorca projektowego Obserwator, a następnie przedstaw
jego implementację w języku C++. W swoim opisie uwzględnij, jak wzorzec Obserwator
umożliwia komunikację między obiektami w systemie, pozwalając na automatyczne powiadamianie
i aktualizację zainteresowanych obiektów przy zmianie stanu. Zaprezentuj kompletny
przykład kodu, który ilustruje jego działanie i sposób użycia w praktycznej aplikacji.
*/

// Obserwator jest wzorcem projektowym, który pozwala zdefiniować mechanizm subskrybcji.
// Zmiana stanu jednego obiektu (podmiotu) skutkuje automatycznym powiadomieniem
// i aktualizacją wszystkich zależnych od niego obiektów (obserwatorów).
// Jest to przydatne w sytuacjach, gdzie obiekty muszą być informowane o zmianach
// stanu innych obiektów w systemie.


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Interfejs obserwatora
class Observer {
public:
    virtual void update(const std::string& name, int age) = 0;
};

// Klasa podmiotu
class Cow {
private:
    std::string name;
    int age;
    std::vector<Observer*> observers;

public:
    Cow() : name("Mućka"), age(7) {}

    void setName(const std::string& newName) {
        name = newName;
        notify();
    }
    std::string getName() const { return name; }
    void setAge(int newAge) {
        age = newAge;
        notify();
    }
    int getAge() const { return age; }
    void attach(Observer* observer) { observers.push_back(observer); }
    void detach(Observer* observer) {
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }
    void notify() {
        for (Observer* observer : observers) {
            observer->update(name, age);
        }
    }
    void makeSound() {
        std::cout << "Muuu" << std::endl;
    }
};

// Przykładowy obserwator
class Farmer : public Observer {
private:
    std::string farmerName;
public:
    Farmer(const std::string& name) : farmerName(name) {}

    void update(const std::string& name, int age) override {
        std::cout << "Farmer " << farmerName << " został powiadomiony. Obecna krowa to "
         << name<< ", wiek " << age << std::endl;
    }
};

// Inny przykładowy obserwator
class Vet : public Observer {
public:
    void update(const std::string& name, int age) override {
        std::cout << "Weterynarz został powiadomiony. Obecna krowa to " << name
         << ", wiek " << age << std::endl;
    }
};

int main() {
    Cow* cow = new Cow();
    Farmer* farmer = new Farmer("Rafał");
    Vet* vet = new Vet();

    cow->attach(farmer);
    cow->attach(vet);

    cow->makeSound();
    cow->setName("Mućka");
    cow->setAge(5);

    cow->detach(farmer);

    cow->setName("Łaciatka");

    delete cow;
    delete farmer;
    delete vet;

    return 0;
}