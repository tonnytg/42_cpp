#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int value) : _value(value << _fractionalBits) {}

Fixed::Fixed(const Fixed& other) : _value(other._value) {}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &other) {
        _value = other._value;
    }
    return *this;
}

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(_value + other._value);
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(_value - other._value);
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed((_value * other._value) >> _fractionalBits);
}

Fixed Fixed::operator/(const Fixed& other) const {
    return Fixed((_value << _fractionalBits) / other._value);
}
