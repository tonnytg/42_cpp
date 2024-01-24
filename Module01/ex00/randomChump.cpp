#include "Zombie.hpp"

void randomChump( std::string name ) {
	
	Zombie *zombie;

	zombie = new Zombie;

	zombie->SetName(name);
	zombie->announce();

	delete zombie;
}