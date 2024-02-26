#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ClapTrap {
protected:
    std::string name;
    int hitPoints;
    int energyPoints;
    int attackDamage;
public:
    ClapTrap(const std::string& name);
    virtual ~ClapTrap();
    virtual void attack() const;
};
