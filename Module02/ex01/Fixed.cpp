#include "Fixed.hpp"

#include <cmath> // For roundf function

// Constructors
Fixed::Fixed() : _value(0) {
	std::cout << "TYPE constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << _fractionalBits) {}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionalBits))) {}

Fixed::Fixed(const Fixed& other) : _value(other._value) {}

// Destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// Getter and setter for value
int Fixed::getRawBits() const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

// Member functions to convert fixed-point value
float Fixed::toFloat() const {
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
    return _value >> _fractionalBits;
}

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    return os << fixed.toFloat();
}
