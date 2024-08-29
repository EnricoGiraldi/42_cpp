#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <stdexcept>

class RPN {
public:
    RPN(const std::string& expression);
    ~RPN();

    int evaluate();

private:
    std::string _expression;
    std::stack<int> _stack;

    void processToken(const std::string& token);
    bool isOperator(const std::string& token) const;
    int applyOperator(const std::string& token, int a, int b) const;
};

#endif
