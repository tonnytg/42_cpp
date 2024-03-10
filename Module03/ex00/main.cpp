#include "ClapTrap.hpp"
#include <iostream>

int main() {

    ClapTrap cp1("Player 1", 10, 10, 0);

	cp1.setHitPoints(10);
    cp1.setEnergyPoints(10);
	cp1.setAttackDamage(0);

    cp1.attack("test1");
    cp1.attack("test2");
    cp1.attack("test3");
    cp1.attack("test4");
    cp1.attack("test5");

	cp1.setAttackDamage(3);

    cp1.attack("test6");
    cp1.attack("test7");
    cp1.attack("test8");
    cp1.attack("test9");

	cp1.getInfo();

    cp1.beRepaired(5);

    cp1.attack("test10");

    return 0;
}
