#ifndef PMERGEME_H
#define PMERGEME_H

#include <vector>
#include <deque>
#include <iostream>

class PmergeMe {
    private:
        std::vector<int> _vec;
        std::deque<int> _deq;
        
        template <typename T>
        void mergeInsertSort(T &container);
        
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
		~PmergeMe();

        PmergeMe &operator=(const PmergeMe &other);

        void fillContainers(const int *array, size_t size);
        void displayResults();
};

#endif
