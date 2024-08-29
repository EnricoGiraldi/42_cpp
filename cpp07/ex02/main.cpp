#include <iostream>
#include "Array.hpp"

int main() {
    try {
        Array<int> arr1(5); 
        for (unsigned int i = 0; i < arr1.size(); ++i) {
            arr1[i] = i + 1;
        }

        std::cout << "arr1: ";
        for (unsigned int i = 0; i < arr1.size(); ++i) {
            std::cout << arr1[i] << " ";
        }
        std::cout << std::endl;

        Array<int> arr2 = arr1; 

        std::cout << "arr2 (copied from arr1): ";
        for (unsigned int i = 0; i < arr2.size(); ++i) {
            std::cout << arr2[i] << " ";
        }
        std::cout << std::endl;

        arr2[2] = 42; 
        std::cout << "arr2 after modification: ";
        for (unsigned int i = 0; i < arr2.size(); ++i) {
            std::cout << arr2[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "arr1 after arr2 modification: ";
        for (unsigned int i = 0; i < arr1.size(); ++i) {
            std::cout << arr1[i] << " ";
        }
        std::cout << std::endl;

        Array<int> arr3;
        arr3 = arr1; 
        std::cout << "arr3 (assigned from arr1): ";
        for (unsigned int i = 0; i < arr3.size(); ++i) {
            std::cout << arr3[i] << " ";
        }
        std::cout << std::endl;

        
        std::cout << "Accessing out of bounds: ";
        std::cout << arr1[10] << std::endl; 

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

