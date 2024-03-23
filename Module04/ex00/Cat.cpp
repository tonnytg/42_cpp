#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat constructor called" << std::endl;
    this->setType("Cat");
};

Cat::~Cat() {
    std::cout << "Cat deconstruction called" << std::endl;
};

Cat& Cat::operator=(Cat const & src)
{
    if (this == &src) {
        return *this;
    }

    std::cout << "Cat copy assignment operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const {
    std::cout << this->getType() << " makes Meow!" << std::endl;
}