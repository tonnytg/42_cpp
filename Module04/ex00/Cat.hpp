#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat(std::string const &type);
		Cat(Cat const &cat);
		~Cat();

		Cat &operator=(Cat const &copy);

		std::string const &getType(void) const;

		void setType(std::string const &type);

		void makeSound(void) const;
};

#endif
