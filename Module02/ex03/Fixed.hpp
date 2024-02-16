#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _value;
    static const int _fractionalBits = 8;

public:
    // Constructors
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& other);

    // Destructor
    ~Fixed();

    // Getter and setter for value
    int getRawBits() const;
    void setRawBits(int const raw);

    // Member functions to convert fixed-point value
    float toFloat() const;
    int toInt() const;

    // Overload of comparison operators
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    // Overload of arithmetic operators
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // Overload of increment/decrement operators
    Fixed& operator++();    // Pre-increment
    Fixed operator++(int);  // Post-increment
    Fixed& operator--();    // Pre-decrement
    Fixed operator--(int);  // Post-decrement

    // Static member functions to find minimum and maximum
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

    // Overload of the insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
};

#endif // FIXED_HPP
