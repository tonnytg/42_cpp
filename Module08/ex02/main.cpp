#include "MutantStack.hpp"

int main()
{
	{
		std::cout << "Stack:" << std::endl;
		MutantStack<int> mstack;
		std::cout << "Push 10" << std::endl;
		mstack.push(10);
		std::cout << "Push 42" << std::endl;
		mstack.push(42);
		std::cout << "Top: " << mstack.top() << std::endl;
		std::cout << "Stack size: " << mstack.size() << std::endl;
		std::cout << "---" << std::endl;
		std::cout << "Pop" << std::endl;
		mstack.pop();
		std::cout << "Top: " << mstack.top() << std::endl;
		std::cout << "Stack size: " << mstack.size() << std::endl;
		std::cout << "---" << std::endl;
	}
	{
		std::cout << "Iterators:" << std::endl;
		MutantStack<int> nstack;
		nstack.push(10);
		nstack.push(24);
		nstack.push(42);
		std::cout << "Stack size: " << nstack.size() << std::endl;
		MutantStack<int>::iterator it = nstack.begin();
		MutantStack<int>::iterator ite = nstack.end();

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "Reverse Iterator:" << std::endl;
		std::reverse_iterator<MutantStack<int>::iterator> rit = nstack.rbegin();
		std::reverse_iterator<MutantStack<int>::iterator> rite = nstack.rend();

		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}
	}
	return 0;
}
