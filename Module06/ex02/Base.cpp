# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base::~Base() {
}

Base *generate(void) {
	srand((unsigned)time(0));
	int randomizer = (rand() % 3);

	switch (randomizer) {
		case 0:
			return (new A());
			break;
		case 1:
			return (new B());
			break;
		case 2:
			return (new C());
			break;
	}
	return (NULL);
}

void identify(Base *p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "Type pointer: A\n";
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "Type pointer: B\n";
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "Type pointer: C\n";
    } else
		std::cout << "Invalid pointer\n";
}

void identify(Base& p) {
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << "Type reference: A\n";
	} 
	catch (const std::exception& e1) {
		try {
		B b = dynamic_cast<B&>(p);
		std::cout << "Type reference: B\n";
		}
		catch (const std::exception& e2) {
			try {
				C c = dynamic_cast<C&>(p);
				std::cout << "Type reference: C\n";
			}
			catch (const std::exception& e3) {
				std::cerr << "Invalid reference\n";
			}
		}
	}
}
