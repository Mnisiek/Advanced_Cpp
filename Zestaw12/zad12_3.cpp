
/*
Opisz funkcję oraz zastosowanie wzorca projektowego Dekorator, a następnie przedstaw
jego implementację w języku C++. W swoim opisie uwzględnij, jak wzorzec Dekorator
umożliwia dynamiczne dodawanie nowych funkcjonalności do obiektów bez modyfikowania
ich kodu źródłowego. Zaprezentuj kompletny przykład kodu, który ilustruje jego
działanie i sposób użycia w praktycznej aplikacji.
*/

// Dekorator jest wzorcem projektowym, który pozwala dodać nowe funkcjonalności
// obiektom poprzez umieszczanie tych obiektów w specjalnych obiektach opakowujących.
// Dekoratory są używane do rozszerzania funkcjonalności obiektów w elastyczny
// sposób, bez konieczności tworzenia dużych hierachii dziedziczenia.


#include <iostream>
#include <string>
#include <memory>

class Cow {
public:
    virtual ~Cow() = default;
    virtual void makeSound() const = 0;
    virtual std::string getName() const = 0;
};

class BasicCow : public Cow {
private:
    std::string name;
public:
    BasicCow(const std::string& name) : name(name) { }

    std::string getName() const override { return name; }
    void makeSound() const override {
        std::cout << name << " robi Muuu!" << std::endl;
    }
};

// Klasa dekoratora
class CowDecorator : public Cow {
protected:
    std::shared_ptr<Cow> decoratedCow;
public:
    CowDecorator(std::shared_ptr<Cow> cow) : decoratedCow(cow) { }

    std::string getName() const override { return decoratedCow->getName(); }
    void makeSound() const override { decoratedCow->makeSound(); }
};

// Konkretne dekoratory
class LoudCow : public CowDecorator {
public:
    LoudCow(std::shared_ptr<Cow> cow) : CowDecorator(cow) { }

    void makeSound() const override {
        std::cout << decoratedCow->getName() << " robi bardzo głośne muuu!" << std::endl;
    }
};

class HappyCow : public CowDecorator {
public:
    HappyCow(std::shared_ptr<Cow> cow) : CowDecorator(cow) {}

    void makeSound() const override {
        CowDecorator::makeSound();
        std::cout << decoratedCow->getName() << " bardzo wesoło robi muuu!" << std::endl;
        std::cout << std::endl;
    }
};

class DepressedCow : public CowDecorator {
public:
    DepressedCow(std::shared_ptr<Cow> cow) : CowDecorator(cow) { }
    
    void makeSound() const override {
        CowDecorator::makeSound();
        std::cout << decoratedCow->getName() << " bardzo smutno robi muuu!" << std::endl;
        std::cout << std::endl;
    }
};


int main() {
    std::shared_ptr<Cow> cow = std::make_shared<BasicCow>("Mućka");
    std::shared_ptr<Cow> loudCow = std::make_shared<LoudCow>(cow);
    std::shared_ptr<Cow> happyLoudCow = std::make_shared<HappyCow>(loudCow);
    std::shared_ptr<Cow> depressedLoudCow = std::make_shared<DepressedCow>(loudCow);


    cow->makeSound();
    loudCow->makeSound();
    happyLoudCow->makeSound();
    depressedLoudCow->makeSound();

    return 0;
}
