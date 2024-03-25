#include "Dog.hpp"

Dog::Dog() {
    this->setType("Dog");
	this->_brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
};

Dog::Dog(const Dog *dog) {
    this->setType(dog->getType());
    this->_brain = new Brain(dog->getBrain());
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &other) {
    this->setType(other.getType());
    this->_brain = new Brain(other.getBrain());
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
	delete this->_brain;
    std::cout << "Dog deconstruction called" << std::endl;
};

Dog& Dog::operator=(Dog const & src)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this == &src) {
        return *this;
    }

    this->_brain = src._brain;
    this->_type = src._type;
    return *this;
}

Brain Dog::getBrain() const {
    return  *_brain;
}

bool Dog::setBrain(Brain* brain) {

    delete _brain;
    _brain = brain;
    return true;
}

std::string Dog::getIdea(int index) const {
    return this->_brain->getIdeas(index);
}

bool Dog::setIdea(const std::string idea, int index) const {
    std::cout <<"["<< index << "]" << "dog will save idea:" << idea << std::endl;
    return this->_brain->setIdeas(idea, index);
}

void Dog::makeSound() const {
    std::cout << this->getType() << " makes Wooof!" << std::endl;
}