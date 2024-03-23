#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include <iostream>
#include <string>

class Dog : public Animal {
    public:
        Dog();
        ~Dog();
        Dog& operator=(Dog const & src);
        void makeSound() const;
};

#endif // DOG_H