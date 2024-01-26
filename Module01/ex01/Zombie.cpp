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

void announce( void ) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void randomChump( std::string name ) {
	
	Zombie *zombie;

	zombie = new Zombie;

	zombie->SetName(name);
	zombie->announce();

	delete zombie;
}

Zombie* newZombie( std::string name );
void randomChump( std::string name );