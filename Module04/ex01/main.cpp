#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {

	Animal *animal = new Animal();
	animal->makeSound();

    Dog *dog = new Dog();
    dog->makeSound();
    dog->setIdea("dog idea 1", 1);

    Dog *dog2 = new Dog(dog);
    dog->setIdea("dog idea 1 replaced", 1);
    std::cout << "Dog2 Idea from dog1: " << dog2->getIdea(1) << std::endl;

	Cat *cat = new Cat();
	cat->setIdea("cat idea 1", 1);
	std::cout << cat->getIdea(1) << " " << std::endl;

	std::cout << "------- ANIMAL HORDE --------" << std::endl;
	Animal *animals[4];
	for (int i = 0; i < 4; i++) {
			if (i % 2 == 0)
					animals[i] = new Dog();
			else
					animals[i] = new Cat();
	}

	for (int i = 0; i < 4; i++)
			animals[i]->makeSound();

	std::cout << "------- TOTAL DESTRUCTION --------" << std::endl;
	for (int i = 0; i < 4; i++)
			delete animals[i];

	delete animal;
    delete dog2;
    delete dog;
	delete cat;

}