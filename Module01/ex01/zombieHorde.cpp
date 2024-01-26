#include "Zombie.hpp"
#include <string>

Zombie* zombieHorde( int n, std::string name ) {

	Zombie *horde = new Zombie[n];

	for (int i = 0; i < n; i++) {

		char letter;
		std::string newName;

		letter = 'a' + i;
		newName = name + "_" + letter;

		horde[i].SetName(newName);
	}

	return horde;
}