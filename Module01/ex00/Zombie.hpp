#include <string>
#include <iostream>

class Zombie {
	private:
		std::string _name;

	public:

		Zombie();
		~Zombie();

		void SetName(std::string name);
		void announce( void );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );