#include "Zombie.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string gerarNomeAleatorio(int size) {
    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string randomName = "";

    std::srand(static_cast<unsigned int>(std::time(NULL)));

    for (int i = 0; i < size; i++) {
        int j = std::rand() % alphabet.size();
        randomName += alphabet[j];
    }

    return randomName;
}

int main() {

	Zombie *zombie = new Zombie();

	zombie->SetName("Antonio");

	zombie->announce();

	
	Zombie *newZombie;

	newZombie = zombie->newZombie("Gomes");

	newZombie->announce();

	newZombie->randomChump(gerarNomeAleatorio(10));

	delete newZombie;

	delete zombie;

	return 0;
}