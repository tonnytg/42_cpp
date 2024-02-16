#include <iostream>
#include "ClapTrap.hpp"

int main() {
    ClapTrap clap("CL4P-TP");

    clap.attack("Bandit");
    clap.takeDamage(3);
    clap.beRepaired(2);
    clap.attack("Bandit");
    clap.attack("Bandit");
    clap.takeDamage(15);
    clap.beRepaired(5);
    clap.attack("Bandit");

    return 0;
}
