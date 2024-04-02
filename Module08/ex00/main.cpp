#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int main()
{
	{
		std::vector<int> vector(1, 1);
		std::vector<int>::iterator vectorIterator;
		vectorIterator = ::easyfind(vector, 1);
		std::cout << *vectorIterator << std::endl;
	}
	{
		std::deque<int> deque(1, 2);
		std::deque<int>::iterator dequeIterator;
		dequeIterator = ::easyfind(deque, 2);
		std::cout << *dequeIterator << std::endl;
	}
	{
		std::list<int> list(1, 3);
		std::list<int>::iterator listIterator;
		listIterator = ::easyfind(list, 3);
		std::cout << *listIterator << std::endl;
	}
}
