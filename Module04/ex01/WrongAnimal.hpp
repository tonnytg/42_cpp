#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <iostream>
#include <string>

class WrongAnimal {
protected:
    std::string _type;

public:
    WrongAnimal();
    virtual ~WrongAnimal();
    WrongAnimal& operator=(WrongAnimal const & src);

    std::string getType() const;
    void setType(const std::string& type);

    virtual void makeSound() const;
};

#endif