#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
    this->setType("Cat");
    std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(std::string const &type) : Animal(type) {
    std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat &cat) {
    *this = cat;
    std::cout << "Cat copy" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat) {
    std::cout << "Cat copy operator called" << std::endl;
    if (this != &cat) {
        this->_type = cat._type;
    }
    return *this;
}

std::string const &Cat::getType() const {
    return this->_type;
}

void Cat::setType(const std::string &type) {
    this->_type = type;
}

void Cat::makeSound(void) const {
    std::cout << "Cat makes sound Meow!" << std::endl;
}
