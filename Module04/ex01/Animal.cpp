#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Animal constructor called" << std::endl;
    this->setType("Animal");
};

Animal::Animal(const Animal &other) {
    this->setType(other.getType());
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal deconstruction called" << std::endl;
};

std::string Animal::getType() const {
    return _type;
}

void Animal::setType(const std::string& type) {
    this->_type = type;
}

Animal& Animal::operator=(Animal const & src)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this == &src) {
        return *this;
    }

    return *this;
}

void Animal::makeSound() const {
    std::cout << this->getType() << " makes some noises" << std::endl;
}