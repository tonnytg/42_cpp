#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class WrongCat : public WrongAnimal {
private:
    Brain *_brain;

public:
    WrongCat();
	WrongCat(const WrongCat *wrongCat);
	WrongCat(const WrongCat &other);
    ~WrongCat();
    WrongCat& operator=(WrongCat const & src);

    Brain getBrain() const;
    bool setBrain(Brain* brain);

    std::string getIdea(int index) const;
    bool setIdea(const std::string idea, int index) const;

    void makeSound() const;
};

#endif //WRONGCAT_H