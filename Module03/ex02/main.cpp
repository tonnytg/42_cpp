#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {

    ClapTrap cp1("Player 1", 10, 10, 0);

    cp1.setEnergyPoints(10);
    cp1.setHitPoints(10);
    cp1.attack("test1");
    cp1.attack("test2");
    cp1.attack("test3");
    cp1.attack("test4");
    cp1.attack("test5");
    cp1.attack("test6");
    cp1.attack("test7");

    cp1.getInfo();

    cp1.beRepaired(5);
    cp1.beRepaired(5);
    cp1.beRepaired(5);
    cp1.attack("test10");

    cp1.getInfo();

    ScavTrap robot("ScavTrap");

    robot.getInfo();

    robot.attack("cp1");
    cp1.takeDamage(robot.getAttackDamage());

    cp1.getInfo();

    robot.guardGate();
	robot.getInfo();

    FragTrap fg("HighFivesGuy");

	fg.getInfo();

    fg.highFivesGuys();

    return 0;
}
