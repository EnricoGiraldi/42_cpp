#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    
    Span(unsigned int N);

    Span(const Span& other);

    Span& operator=(const Span& other);

    ~Span();

   
    void addNumber(int number);
    int shortestSpan() const;
    int longestSpan() const;

    
    template <typename InputIterator>
    void addNumbers(InputIterator begin, InputIterator end) {
        if (std::distance(begin, end) + _numbers.size() > _maxSize) {
            throw std::overflow_error("Adding these elements will exceed the maximum size of Span");
        }
        _numbers.insert(_numbers.end(), begin, end);
    }
};

#endif
