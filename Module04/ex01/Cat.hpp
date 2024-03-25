#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal {
private:
    Brain *_brain;

public:
    Cat();
	Cat(const Cat *cat);
	Cat(const Cat &other);
    ~Cat();
    Cat& operator=(Cat const & src);

    Brain getBrain() const;
    bool setBrain(Brain* brain);

    std::string getIdea(int index) const;
    bool setIdea(const std::string idea, int index) const;

    void makeSound() const;
};

#endif //CAT_H