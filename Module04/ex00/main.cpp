#include "Dog.h"
#include "Cat.h"

int main() {
    Animal animal;
    Animal animal2;

    Dog dog;
    Dog dog2;

    Cat cat;
    Cat cat2;

    animal.makeSound();
    animal2 = animal;
    animal2.makeSound();

    dog.makeSound();
    dog2 = dog;
    dog2.makeSound();


    cat.makeSound();
    cat2 = cat;
    cat2.makeSound();
}
