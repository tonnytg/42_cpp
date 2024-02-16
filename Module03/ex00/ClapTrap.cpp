#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap constructor called. Name: " << _name << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called. Name: " << _name << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (_energyPoints >= 1) {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints -= 1;
    } else {
        std::cout << "ClapTrap " << _name << " has no energy left to attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints > 0) {
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
        _hitPoints -= amount;
    } else {
        std::cout << "ClapTrap " << _name << " is already out of hit points and can't take any more damage!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints > 0) {
        std::cout << "ClapTrap " << _name << " is being repaired, gaining " << amount << " hit points!" << std::endl;
        _hitPoints += amount;
    } else {
        std::cout << "ClapTrap " << _name << " is unable to be repaired as it is out of hit points!" << std::endl;
    }
}
