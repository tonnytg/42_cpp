#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
};

Brain::Brain(const Brain &brain) {
    *this = brain;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain desconstructor called" << std::endl;
};

Brain& Brain::operator=(Brain const & src) {
    if(this != &src) {
        std::cout << "Brain copy operator called" << std::endl;
        for (int i = 0; i < 100; i++)
        {
            this->_ideas[i] = src._ideas[i];
        }
    }
    return *this;
};

const std::string &Brain::getIdeas(int const &index) const {

    if (index > 0 && index < 100) {
        return this->_ideas[index];
    }

    return this->_ideas[0];
}

bool Brain::setIdeas(const std::string &idea, int index) {

    if (index >= 0 && index < 100) {
        this->_ideas[index] = idea;
        std::cout << "[" << index << "]" << "brain saved idea:" << idea << std::endl;
        return true;
    }

    std::cout << "Index is out of range" << std::endl;
    return false;
}