#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include <string>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

private:
    std::string _name;

public:

    ScavTrap();
    ScavTrap(const std::string& name);
    ~ScavTrap();

    void attack(const std::string& target);

    void guardGate();

};


#endif //SCAVTRAP_HPP
