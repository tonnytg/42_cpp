#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {
protected:
    std::string _type;

public:
    Animal();
    Animal(std::string type);
    virtual ~Animal();

    std::string getType() const;
    bool setType(std::string type);

    Animal &operator=(const Animal &animal);

    virtual void makeSound() const;

};

#endif