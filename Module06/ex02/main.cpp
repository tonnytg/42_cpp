# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

int main()
{
	Base *random = generate();
	A *a = new A();
	B *b = new B();
	C *c = new C();

	std::cout << "\nType A test:\n";
	identify(a);
	identify(*a);

	std::cout << "\nType B test:\n";
	identify(b);
	identify(*b);

	std::cout << "\nType C test:\n";
	identify(c);
	identify(*c);

	std::cout << "\nRandom type test:\n";
	identify(random);
	identify(*random);

	delete (a);
	delete (b);
	delete (c);
	delete (random);

  	return (0);
}