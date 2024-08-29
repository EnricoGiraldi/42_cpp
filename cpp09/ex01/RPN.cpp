#include "RPN.hpp"
#include <sstream>
#include <iostream>
#include <cstdlib>

RPN::RPN(const std::string& expression) : _expression(expression) {}

RPN::~RPN() {}

int RPN::evaluate() {
    std::istringstream ss(_expression);
    std::string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            _stack.push(std::atoi(token.c_str()));
        } else if (isOperator(token)) {
            if (_stack.size() < 2) {
                throw std::runtime_error("Error: invalid expression.");
            }
            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();
            int result = applyOperator(token, a, b);
            _stack.push(result);
        } else {
            throw std::runtime_error("Error: invalid token.");
        }
    }

    if (_stack.size() != 1) {
        throw std::runtime_error("Error: invalid expression.");
    }

    return _stack.top();
}

void RPN::processToken(const std::string& token) {
    
    if (isdigit(token[0])) {
        _stack.push(std::atoi(token.c_str()));
    } else if (isOperator(token)) {
        if (_stack.size() < 2) {
            throw std::runtime_error("Error: invalid expression.");
        }
        int b = _stack.top(); _stack.pop();
        int a = _stack.top(); _stack.pop();
        int result = applyOperator(token, a, b);
        _stack.push(result);
    } else {
        throw std::runtime_error("Error: invalid token.");
    }
}

bool RPN::isOperator(const std::string& token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int RPN::applyOperator(const std::string& token, int a, int b) const {
    if (token == "+") return a + b;
    if (token == "-") return a - b;
    if (token == "*") return a * b;
    if (token == "/") {
        if (b == 0) throw std::runtime_error("Error: division by zero.");
        return a / b;
    }
    throw std::runtime_error("Error: unknown operator.");
}
