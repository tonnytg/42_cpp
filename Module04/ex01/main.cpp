#include "Dog.hpp"

int main() {
	Dog basic;
	{
		basic.setIdea("teste 1.0", 1);
		Dog tmp = basic;
		std::cout << "Basic: " << basic.getIdea(1) << std::endl;
		std::cout << "TMP: " << tmp.getIdea(1) << std::endl;
		basic.setIdea("teste 1.1", 1);
		std::cout << "Basic: " << basic.getIdea(1) << std::endl;
		std::cout << "TMP: " << tmp.getIdea(1) << std::endl;
	}
}