#ifndef WRONGANIMAL_H
#define WRONGANIMAL_H

#include <string>
#include <iostream>

class WrongAnimal {
protected:
    std::string _type;

public:
    WrongAnimal();
    ~WrongAnimal();
    WrongAnimal& operator=(WrongAnimal const & src);

    std::string getType() const;
    void setType(const std::string& type);

    virtual void makeSound() const;
};

#endif //WRONGANIMAL_H