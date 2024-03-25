#include "Cat.hpp"

Cat::Cat() {
    this->setType("Cat");
    this->_brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
};

Cat::Cat(const Cat *cat) {
    this->setType(cat->getType());
    this->_brain = new Brain(cat->getBrain());
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &other) {
    this->setType(other.getType());
    this->_brain = new Brain(other.getBrain());
    std::cout << "Cat copy constructor called" << std::endl;
}


Cat::~Cat() {
    delete this->_brain;
    std::cout << "Cat deconstruction called" << std::endl;
};

Cat& Cat::operator=(Cat const & src)
{
    if (this == &src) {
        return *this;
    }

    this->_type = src._type;
    this->_brain = src._brain;
    std::cout << "Cat copy assignment operator called" << std::endl;
    return *this;
}

Brain Cat::getBrain() const {
    return  *_brain;
}

bool Cat::setBrain(Brain* brain) {

    delete _brain;
    _brain = brain;
    return true;
}

std::string Cat::getIdea(int index) const {
    return this->_brain->getIdeas(index);
}

bool Cat::setIdea(const std::string idea, int index) const {
    std::cout <<"["<< index << "]" << "cat will save idea:" << idea << std::endl;
    return this->_brain->setIdeas(idea, index);
}

void Cat::makeSound() const {
    std::cout << this->getType() << " makes Meow!" << std::endl;
}