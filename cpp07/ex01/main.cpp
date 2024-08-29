#include <iostream>
#include "iter.hpp"


template <typename T>
void increment(T &x) {
    ++x;
}


template <typename T>
void print(T &x) {
    std::cout << x << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    std::string stringArray[] = {"Hello", "World", "!"};

    std::cout << "Array before iter (int): ";
    iter(intArray, 5, print);
    std::cout << std::endl;

    iter(intArray, 5, increment);

    std::cout << "Array after iter (int): ";
    iter(intArray, 5, print);
    std::cout << std::endl;

   
    return 0;
}


