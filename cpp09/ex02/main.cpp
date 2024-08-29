#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>  
#include <ctime>    


template <typename Container>
void printContainer(const Container& container) {
    std::cout << "Before: ";
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        if (it != container.begin()) std::cout << " ";
        std::cout << *it;
    }
    std::cout << std::endl;
}


template <typename Container>
void printSortedContainer(const Container& container) {
    std::cout << "After: ";
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        if (it != container.begin()) std::cout << " ";
        std::cout << *it;
    }
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::deque<int> deq;

    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        if (num <= 0) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        vec.push_back(num);
        deq.push_back(num);
    }

   
    printContainer(vec);
    std::clock_t start = std::clock();
    PmergeMe::mergeInsertSort(vec);
    std::clock_t end = std::clock();
    double elapsedVector = double(end - start) / CLOCKS_PER_SEC * 1000000; 
    printSortedContainer(vec);
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " 
              << elapsedVector << " us" << std::endl;

   
    start = std::clock();
    PmergeMe::mergeInsertSort(deq);
    end = std::clock();
    double elapsedDeque = double(end - start) / CLOCKS_PER_SEC * 1000000; 
  
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " 
              << elapsedDeque << " us" << std::endl;

    return 0;
}
