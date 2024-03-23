#include "WrongCat.hpp"

WrongCat::WrongCat() {
    this->setType("WrongCat");
    this->_brain = new Brain();
    std::cout << "WrongCat constructor called" << std::endl;
};

WrongCat::WrongCat(const WrongCat *wrongCat) {
    this->setType(wrongCat->getType());
    this->_brain = new Brain(wrongCat->getBrain());
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat() {
    delete this->_brain;
    std::cout << "WrongCat deconstruction called" << std::endl;
};

WrongCat& WrongCat::operator=(WrongCat const & src)
{
    if (this == &src) {
        return *this;
    }

    this->_type = src._type;
    this->_brain = src._brain;
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    return *this;
}

Brain WrongCat::getBrain() const {
    return  *_brain;
}

bool WrongCat::setBrain(Brain* brain) {

    delete _brain;
    _brain = brain;
    return true;
}

std::string WrongCat::getIdea(int index) const {
    return this->_brain->getIdeas(index);
}

bool WrongCat::setIdea(const std::string idea, int index) const {
    std::cout <<"["<< index << "]" << "wrongCat will save idea:" << idea << std::endl;
    return this->_brain->setIdeas(idea, index);
}

void WrongCat::makeSound() const {
    std::cout << this->getType() << " makes Meow!" << std::endl;
}