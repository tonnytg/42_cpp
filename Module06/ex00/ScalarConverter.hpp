#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <limits.h>


enum validTypes { TChar, TInt, TFloat, TDouble, TNaN, TInf, TInvalid };
typedef bool (*types)(const std::string);
typedef void (*printFunctions)(const std::string);

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const& src);
    ScalarConverter& operator=(ScalarConverter const& rhs);
    ~ScalarConverter();
public:
    static void converter(const std::string value);
};

bool isFloat(const std::string value);
bool isInt(const std::string value);
bool isChar(const std::string value);
bool isDouble(const std::string value);
validTypes getType(const std::string value);
void fromChar(const std::string value);
void fromInt(const std::string value);
void fromFloat(const std::string value);
void fromDouble(const std::string value);
bool isANanType(const std::string value);
bool isInfType(const std::string value);
void fromNanType(const std::string value);
void fromInfType(const std::string value);
void fromInvalidType(const std::string value);

#endif