#include "ScavTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(100), energyPoints(50), attackDamage(20) {}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " says: 'I'm melting! Melting! Oh, what a world!'" << std::endl;
}

void ClapTrap::attack() const {
    std::cout << "ClapTrap " << name << " attacks, causing " << attackDamage << " points of damage!" << std::endl;
}

class ScavTrap : public ClapTrap {
public:
    ScavTrap(const std::string& name);
    ~ScavTrap();
    void attack() const override;
    void guardGate() const;
};

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << name << " says: 'I'll die the way I lived: annoying!'" << std::endl;
}

void ScavTrap::attack() const {
    std::cout << "ScavTrap " << name << " attacks, causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() const {
    std::cout << "ScavTrap " << name << " is now in Gatekeeper mode." << std::endl;
}

int main() {
    ClapTrap claptrap("Claptrap");
    claptrap.attack();

    ScavTrap scavtrap("Scavtrap");
    scavtrap.attack();
    scavtrap.guardGate();

    return 0;
}