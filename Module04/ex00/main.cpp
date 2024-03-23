#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

int main() {

    const Animal *animal = new Animal;
    std::cout << animal->getType() << " " << std::endl;
    animal->makeSound();

    const Dog *dog = new Dog;
    std::cout << dog->getType() << " " << std::endl;
    dog->makeSound();

    const Cat *cat = new Cat;
    std::cout << cat->getType() << " " << std::endl;
    cat->makeSound();

    const WrongAnimal *wrongAnimal = new WrongAnimal;
    std::cout << wrongAnimal->getType() << " " << std::endl;
    wrongAnimal->makeSound();

    const WrongCat *wrongCat = new WrongCat;
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound();

    delete wrongCat;
    delete wrongAnimal;
    delete cat;
    delete dog;
    delete animal;
}