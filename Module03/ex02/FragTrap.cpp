#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() {
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    this->setName(name);
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
    std::cout << "FragTrap Constructor called. Name: " << this->getName() << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap deconstruction Serena called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap positive high fives request on the standard output" << std::endl;
}