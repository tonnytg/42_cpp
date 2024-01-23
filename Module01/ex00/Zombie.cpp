#include <string>
#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie() {};

Zombie::~Zombie() {
    std::cout << _name << ": ArrgggGgg!" << std::endl;
}

void Zombie::SetName(std::string name) {
	_name = name;
}

void Zombie::announce( void ) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
