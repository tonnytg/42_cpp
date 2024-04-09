#ifndef RPN_H
#define RPN_H

#include <stack>
#include <string>


class RPN {
private:
    std::stack<int> _stack;	
public:
    RPN();
    RPN(const RPN& obj);
	~RPN();

    RPN& operator=(const RPN& obj);

    int calculate(std::string expression);
    bool isValidExpression(const std::string& expression);
};

#endif
