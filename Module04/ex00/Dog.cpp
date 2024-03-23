#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog constructor called" << std::endl;
    this->setType("Dog");
};

Dog::~Dog() {
    std::cout << "Dog deconstruction called" << std::endl;
};

Dog& Dog::operator=(Dog const & src)
{
    if (this == &src) {
        return *this;
    }

    std::cout << "Dog copy assignment operator called" << std::endl;
    return *this;
}

void Dog::makeSound() const {
    std::cout << this->getType() << " makes Wooof!" << std::endl;
}