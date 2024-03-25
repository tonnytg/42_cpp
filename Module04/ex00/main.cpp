#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {

	Animal *animal = new Animal();
	animal->makeSound();

    Animal *dog = new Dog();
    dog->makeSound();

	Animal *cat = new Cat();
	cat->makeSound();

	WrongAnimal *cat2 = new WrongCat;
	cat2->makeSound();

	WrongCat *cat3 = new WrongCat;
	cat3->makeSound();

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
    delete dog;
	delete cat;
	delete cat2;
	delete cat3;
}