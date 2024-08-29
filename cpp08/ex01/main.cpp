#include <iostream>
#include "Span.hpp"

int main() {
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    
    Span sp2 = Span(10000);
    std::vector<int> range(10000);
    for (int i = 0; i < 10000; ++i) {
        range[i] = i * 2;  
    }
    sp2.addNumbers(range.begin(), range.end());

    std::cout << "Shortest Span in sp2: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest Span in sp2: " << sp2.longestSpan() << std::endl;

    return 0;
}
