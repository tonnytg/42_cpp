#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>

class ClapTrap {

private:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;

public:

    ClapTrap();
	ClapTrap(const std::string &name);
    ClapTrap(const std::string& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
    ~ClapTrap();

    ClapTrap &operator=(const ClapTrap &other);

    std::string getName() const;
    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getAttackDamage() const;

    void getInfo() const;

    bool setName(const std::string& name);
    bool setHitPoints(unsigned int amount);
    bool setEnergyPoints(unsigned int amount);
    bool setAttackDamage(unsigned int damage);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif
