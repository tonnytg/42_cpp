#include "WrongCat.hpp"

WrongCat::WrongCat() {
    this->setType("WrongCat");
    std::cout << this->getType() <<" constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << this->getType() <<" deconstruction called" << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << this->getType() << " makes some strange MeoWoof!" << std::endl;
}