#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal {
protected:
    std::string _type;

public:
    Animal();
	Animal(const Animal &other);
    virtual ~Animal();
    Animal& operator=(Animal const & src);

    std::string getType() const;
    void setType(const std::string& type);

    virtual void makeSound() const;
};

#endif