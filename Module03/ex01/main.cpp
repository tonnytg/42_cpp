#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

    robot.setHitPoints(100);
    robot.setEnergyPoints(50);
    robot.setAttackDamage(20);

    robot.getInfo();

    robot.attack("cp1");
    cp1.takeDamage(robot.getAttackDamage());

    cp1.getInfo();

	robot.guardGate();

    return 0;
}
