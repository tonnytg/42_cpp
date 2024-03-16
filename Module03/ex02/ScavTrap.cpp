#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    this->setName(name);
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << "ScavTrap Constructor called. Name: " << this->getName() << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap deconstruction Serena called" << std::endl;
}

void ScavTrap::guardGate() {
	if (this->getEnergyPoints() < 1) {
		std::cout << "ScavTrap this member cannot enter in Gate keeper mode." << std::endl;
	} else {
		std::cout << "ScavTrap this member is now in Gate keeper mode." << std::endl;
	}
    
}

void ScavTrap::attack(const std::string &target) {
    if (this->getEnergyPoints() >= 1) {
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->getAttackDamage() <<  " points of damage!" << std::endl;
        this->setEnergyPoints( this->getEnergyPoints() - 1);
    } else {
        std::cout << "ScavTrap "<< this->_name << " cannot attack because it has no energy points!" << std::endl;
    }
}