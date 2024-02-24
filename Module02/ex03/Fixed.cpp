#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int value) : _value(value << _fractionalBits) {}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionalBits))) {}

Fixed::Fixed(const Fixed &other) : _value(other._value) {}

Fixed::~Fixed() {}

int Fixed::getRawBits() const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

float Fixed::toFloat() const {
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
    return _value >> _fractionalBits;
}

bool Fixed::operator>(const Fixed &other) const {
    return _value > other._value;
}

bool Fixed::operator<(const Fixed &other) const {
    return _value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const {
    return _value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const {
    return _value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const {
    return _value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const {
    return _value != other._value;
}

Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed((_value + other._value) >> _fractionalBits);
}

Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed((_value - other._value) >> _fractionalBits);
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed((_value * other._value) >> _fractionalBits);
}

Fixed Fixed::operator/(const Fixed &other) const {
    return Fixed((_value << _fractionalBits) / other._value);
}

Fixed &Fixed::operator++() {
    ++_value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed &Fixed::operator--() {
    --_value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    return os << fixed.getRawBits() / static_cast<float>(1 << Fixed::_fractionalBits);
}
