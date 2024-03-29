#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const& src) {
    *this = src;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& rhs) {
    (void)rhs;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::converter(const std::string value) {
    validTypes typeOfValue = getType(value);
    printFunctions printFunctions[7] = {
            &fromChar,
            &fromInt,
            &fromFloat,
            &fromDouble,
            &fromNanType,
            &fromInfType,
            &fromInvalidType };
    printFunctions[typeOfValue](value);
}

validTypes getType(const std::string value) {
    types allTypes[6] = { &isChar,
                          &isInt,
                          &isFloat,
                          &isDouble,
                          &isANanType,
                          &isInfType };
    for (int i = 0; i < 6; i++) {
        if (allTypes[i](value)) {
            return validTypes(i);
        }
    }
    return TInvalid;
}

char getIntChar(int value) {
    if (value > 31 && value < 128) {
        return static_cast<char>(value);
    }
    return 0;
}

void fromChar(const std::string value) {
    char c = static_cast<char>(value[0]);
    std::cout << "char: \"" << c << "\"" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void fromInt(const std::string value) {
    int parsedValue = std::atoi(value.c_str());
    char intChar = getIntChar(parsedValue);

    if (intChar) {
        std::cout << "char: \"" << intChar << "\"" << std::endl;
    } else {
        std::cout << "char: " << "Non displayable" << std::endl;
    }

    std::cout << "int: " << value << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(parsedValue) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(parsedValue) << std::endl;
}

void fromFloat(const std::string value) {
    float parsedValue = std::atof(value.c_str());
    int intValue = static_cast<int>(parsedValue);

    char floatChar = getIntChar(intValue);
    if (floatChar) {
        std::cout << "char: \"" << floatChar << "\"" << std::endl;
    } else {
        std::cout << "char: " << "Non displayable" << std::endl;
    }

    std::cout << "int: " << intValue << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << parsedValue << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(parsedValue) << std::endl;
}

void fromDouble(const std::string value) {
    double parsedValue = std::atof(value.c_str());
    int intValue = static_cast<int>(parsedValue);
    char doubleChar = getIntChar(intValue);

    if (doubleChar) {
        std::cout << "char: \"" << doubleChar << "\"" << std::endl;
    } else {
        std::cout << "char: " << "Non displayable" << std::endl;
    }

    std::cout << "int: " << intValue << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(parsedValue) << "f" << std::endl;
    std::cout << "double: " << parsedValue << std::endl;
}

void fromNanType(const std::string value) {
    (void)(value);
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << "nanf" << std::endl;
    std::cout << "double: " << "nan" << std::endl;
}

void fromInfType(const std::string value) {
    (void)(value);
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << "inff" << std::endl;
    std::cout << "double: " << "inf" << std::endl;
}

void fromInvalidType(const std::string value) {
    (void)(value);
    std::cout << "Invalid type" << std::endl;
}

bool isFloat(const std::string value) {
    char* f;
    strtol(value.c_str(), &f, 10);
    if (*f == '.') {
        f++;
    }
    strtol(f, &f, 10);
    std::string check = f;
    if (!check.compare("f\0")) {
        return true;
    }
    return false;
}

bool isInt(const std::string value) {
    char* p;

    strtol(value.c_str(), &p, 10);

    const size_t pointIndex = value.find('.');
    if (pointIndex == std::string::npos && *p == '\0') {
        return true;
    }
    return false;
}

bool isChar(const std::string value) {
    if (value.length() == 1 && (value[0] < 48 || value[0] > 57)) {
        return true;
    }
    return false;
}

bool isDouble(const std::string value) {
    char* f;
    strtol(value.c_str(), &f, 10);
    if (*f == '.') {
        f++;
    }
    strtol(f, &f, 10);
    if (*f == '\0') {
        return true;
    }
    return false;
}

bool isANanType(const std::string value) {
    if (value.compare("nan") == 0 || value.compare("nanf") == 0) {
        return true;
    }
    return false;
}

bool isInfType(const std::string value) {
    if (value.compare("inf") == 0 || value.compare("inff") == 0) {
        return true;
    }
    return false;
}