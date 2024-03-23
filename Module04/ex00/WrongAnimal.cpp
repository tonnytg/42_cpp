#include "WrongAnimal.h"

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal constructor called" << std::endl;
    this->setType("WrongAnimal");
};

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal deconstruction called" << std::endl;
};

std::string WrongAnimal::getType() const {
    return _type;
}

void WrongAnimal::setType(const std::string& type) {
    this->_type = type;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const & src)
{
    if (this == &src) {
        return *this;
    }

    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << this->getType() << " makes some wrong noises ASFGASFADS!" << std::endl;
}