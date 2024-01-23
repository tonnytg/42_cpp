#include "Zombie.hpp"

int main() {

	Zombie *zombie = new Zombie();

	zombie->SetName("Antonio");

	zombie->announce();

	
	Zombie *newZombie;

	newZombie = zombie->newZombie("Gomes");

	newZombie->announce();

	delete newZombie;

	delete zombie;

	return 0;
}