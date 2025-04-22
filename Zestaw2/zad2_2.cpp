/*
2. Zaimplementuj krótki program w którym wykorzystany będzie polimorfizm dynamiczny
oraz polimorfizm statyczny.
*/

#include <iostream>

template <typename T> void soundTemplate(T tab[], int n) {
    for (int i = 0; i < n; ++i) {
        tab[i].makeSound();
    }
}

class AlarmClock {
    public:
    void makeSound() {
        std::cout << "Dryn dryn" << std::endl;
    }
};

class Animal {
    public:
    virtual void makeSound() = 0;
};

class Dog : public Animal {
    public:
    virtual void makeSound() {
        std::cout << "Hau hau" << std::endl;
    }
};

class Cat : public Animal {
    public:
    virtual void makeSound() {
        std::cout << "Miauu" << std::endl;
    }
};

class Cow : public Animal {
    public:
    virtual void makeSound() {
        std::cout << "Muuu" << std::endl;
    }
};


int main()
{
    // polimorfizm dynamiczny
    Animal* tab1[3];
    tab1[0] = new Cat();
    tab1[1] = new Dog();
    tab1[2] = new Cow();

    for (Animal* animal : tab1) {
        animal->makeSound();
    }
    std::cout << std::endl;

    // polimorfizm statyczny
    AlarmClock tab2[1] = {AlarmClock()};
    Cow tab3[2] = {Cow(), Cow()};
    
    soundTemplate(tab2, 1);
    soundTemplate(tab3, 2);

    return 0;
}