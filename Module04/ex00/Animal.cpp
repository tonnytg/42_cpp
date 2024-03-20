#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) {
    this->_type = type;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

bool Animal::setType(std::string type) {
    this->_type = type;
    return true;
}

std::string Animal::getType() const {
    return this->_type;
}

Animal &Animal::operator=(const Animal &animal) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &animal) {
        this->_type = animal._type;
    }
    return *this;
}

void Animal::makeSound(void) const {
    std::cout << "Animal " << this->_type << " made a sound!" << std::endl;
}
