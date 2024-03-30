#include "Data.hpp"

Data::Data() {}

Data::~Data() {}

Data::Data(Data const & src) {
    *this = src;
}

Data & Data::operator=(Data const & src) {
    if (this != &src) {
        this->_n = src._n;
    }
    return *this;
}

Data::Data(int n) : _n(n) {}

int Data::getN() const {
    return this->_n;
}

void Data::setN(int n) {
    this->_n = n;
}
