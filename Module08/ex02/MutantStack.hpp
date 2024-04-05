#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T> {

public:
	MutantStack<T>(void) : std::stack<T>() {}

	MutantStack<T>(const MutantStack<T> &other) {
		*this = other;
	}

	~MutantStack<T>(void) {}

	MutantStack<T> &operator=(const MutantStack<T> &other)
	{
		if (this != &other)
			this->std::stack<T>::operator=(other);
		return (*this);
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin(void) {
		return (this->c.begin());
	}
	iterator end(void) {
		return (this->c.end());
	}

	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

	reverse_iterator rbegin(void) {
		return (this->c.rbegin());
	}
	reverse_iterator rend(void) {
		return (this->c.rend());
	}
};

#endif