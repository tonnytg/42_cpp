#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include <iostream>
#include <string>

class Cat : public Animal {
public:
    Cat();
    ~Cat();
    Cat& operator=(Cat const & src);

    void makeSound() const;
};

#endif //CAT_H