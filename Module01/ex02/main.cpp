#include <iostream>
#include <string>

class Brain {
	private:
		std::string _brain;

	public:
		Brain() {
			_brain = "HI THIS IS BRAIN";
		};

		std::string *getAddress() {
			return &_brain;
		}

		std::string &getReference() {
			return _brain;
		}

		std::string getBrain() {
			return _brain;
		}
};

int main() {

    Brain brain;

    std::string *stringPTR = brain.getAddress();
    std::string &stringREF = brain.getReference();

    std::cout << "Address  : " << stringPTR << "\tValue: " << *stringPTR << std::endl;
    std::cout << "Reference: " << &stringREF << "\tValue: " << stringREF << std::endl;

	return 0;
}