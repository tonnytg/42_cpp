#include "RPN.hpp"
#include <sstream>
#include <iterator>
#include <list>
#include <iostream>
#include <string>

RPN::RPN() { }

RPN::RPN(const RPN& obj) {
    this->_stack = obj._stack;
}

RPN::~RPN() {
    while (!_stack.empty()) _stack.pop();
}

RPN& RPN::operator=(const RPN& obj) {
    if (this != &obj) {
        this->_stack = obj._stack;
    }
    return *this;
}

bool RPN::isValidExpression(const std::string& expression) {
    if (expression.empty()) return false;

    std::string validChars = "0123456789 +-/*";
    for (std::string::const_iterator it = expression.begin(); it != expression.end(); ++it) {
        if (validChars.find(*it) == std::string::npos) return false;
    }
    return true;
}

int RPN::calculate(std::string expression) {
    std::istringstream iss(expression);
    std::list<std::string> tokens;
    std::copy(std::istream_iterator<std::string>(iss),
              std::istream_iterator<std::string>(),
              std::back_inserter(tokens));

    for (std::list<std::string>::iterator it = tokens.begin(); it != tokens.end(); ++it) {
        std::string token = *it;

        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (_stack.size() < 2) {
                std::cerr << "Error" << std::endl;
                return -1;
            }
            int val2 = _stack.top(); _stack.pop();
            int val1 = _stack.top(); _stack.pop();

            if (token == "+") _stack.push(val1 + val2);
            else if (token == "-") _stack.push(val1 - val2);
            else if (token == "*") _stack.push(val1 * val2);
            else if (token == "/") {
                if (val2 == 0) {
                    std::cerr << "Error" << std::endl;
                    return -1;
                }
                _stack.push(val1 / val2);
            }
        }
        else {
            std::stringstream ss(token);
            int num;
            if (!(ss >> num)) {
                std::cerr << "Error: Invalid number" << std::endl;
                return -1;
            }
            _stack.push(num);
        }
    }

    if (_stack.size() != 1) {
        std::cerr << "Error" << std::endl;
        return -1;
    }

    return _stack.top();
}
