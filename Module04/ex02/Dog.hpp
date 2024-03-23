#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal {
private:
    Brain *_brain;

public:
    Dog();
    Dog(const Dog *dog);
    virtual ~Dog();
    Dog& operator=(Dog const & src);

    Brain getBrain() const;
    bool setBrain(Brain* brain);

    std::string getIdea(int index) const;
    bool setIdea(const std::string idea, int index) const;

    void makeSound() const;
};

#endif // DOG_H