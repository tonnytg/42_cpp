#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

void PmergeMe::fillContainers(const int *array, size_t size) {
    _vec.assign(array, array + size);
    _deq.assign(array, array + size);
}

template <typename T>
void PmergeMe::mergeInsertSort(T &container) {
    for(typename T::iterator it = container.begin(); it != container.end(); ++it) {
        typename T::iterator pos = std::upper_bound(container.begin(), it, *it);
        std::rotate(pos, it, it+1);
    }
}

void PmergeMe::displayResults() {
    std::cout << "Initial sequence: ";
    for(size_t i = 0; i < _vec.size(); i++) std::cout << _vec[i] << " ";
    std::cout << "\n";

    clock_t begin = clock();
    mergeInsertSort(_vec);
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    std::cout << "Sorted sequence: ";
    for(size_t i = 0; i < _vec.size(); i++) std::cout << _vec[i] << " ";
    std::cout << std::endl;
    std::cout << "Time elapsed (vector): " << elapsed_secs << std::endl;

    begin = clock();
    mergeInsertSort(_deq);
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    
    std::cout << "Time elapsed (deque): " << elapsed_secs << std::endl;
}
