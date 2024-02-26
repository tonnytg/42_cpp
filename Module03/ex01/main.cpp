#include <iostream>
#include "ScavTrap.hpp"

int main() {
    ScavTrap scav("SC4V-TP");

    scav.attack("Bandit");
    scav.takeDamage(3);
    scav.beRepaired(2);
    scav.attack("Bandit");
    scav.attack("Bandit");
    scav.takeDamage(15);
    scav.beRepaired(5);
    scav.attack("Bandit");
    scav.guardGate();

    return 0;
}
