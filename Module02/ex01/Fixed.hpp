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

    // Overload of the insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
};

#endif // FIXED_HPP
