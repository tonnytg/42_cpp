#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() {

    this->_name = "";
    this->_hitPoints = 0;
    this->_energyPoints = 0;
    this->_attackDamage = 0;

    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) {

    this->setName(name);
    this->setHitPoints(10);
    this->setEnergyPoints(10);
    this->setAttackDamage(0);

    std::cout << "ClapTrap constructor with name called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name, unsigned int hitPoints, unsigned int energyPoints,
                   unsigned int attackDamage) {

    this->setName(name);
    this->setHitPoints(hitPoints);
    this->setEnergyPoints(energyPoints);
    this->setAttackDamage(attackDamage);

    std::cout << "ClapTrap constructor with all atributes called" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap deconstruction ClapTrap called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

std::string ClapTrap::getName() const {
    return this->_name;
}

unsigned int ClapTrap::getHitPoints() const {
    return this->_hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const {
    return this->_energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const {
    return this->_attackDamage;
}

void ClapTrap::getInfo() const{
    std::cout
			  << "\033[1;31m" << "ClapTrap Info: "  << "\033[0m" << this->getName()
              << " - Hit Points: " << this->getHitPoints()
              << " - Attack: " << this->getAttackDamage()
              << " - Energy: " << this->getEnergyPoints()
              << std::endl;
}


bool ClapTrap::setName(const std::string& name) {
    this->_name = name;
    return true;
}

bool ClapTrap::setHitPoints(unsigned int amount) {
    this->_hitPoints = amount;
    return true;
};

bool ClapTrap::setEnergyPoints(unsigned int amount) {
    this->_energyPoints = amount;
    return true;
};

bool ClapTrap::setAttackDamage(unsigned int damage) {
    this->_attackDamage = damage;
    return true;
};

void ClapTrap::attack(const std::string &target) {
    if (this->getEnergyPoints() >= 1) {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage <<  " points of damage!" << std::endl;
        this->setEnergyPoints( this->getEnergyPoints() - 1);
    } else {
        std::cout << "clapTrap "<< this->_name << " cannot attack because it has no energy points!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << this->_name << " takes " << amount <<  " points of damage!" << std::endl;
    this->setHitPoints(this->getHitPoints() - amount);
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->getEnergyPoints() >= 1) {
        this->setHitPoints(this->getHitPoints() + amount);
        this->setEnergyPoints(this->getEnergyPoints() - 1);
        std::cout << "ClapTrap " << this->_name << " repaired " << amount <<  " of hit points!" << std::endl;
    } else {
        std::cout << "ClapTrap " << this->_name << " cannot repair " << amount <<  " of hit point because it has no points of energy!" << std::endl;
    }
}
