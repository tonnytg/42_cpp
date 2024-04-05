#ifndef BASE_HPP
# define BASE_HPP
# include <cstdlib>
# include <iostream>
# include <exception>

class Base {
	public:
		virtual ~Base(void);
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif