#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <cstddef>  

class PmergeMe {
public:
    static void mergeInsertSort(std::vector<int>& vec);
    static void mergeInsertSort(std::deque<int>& deq);

private:
    static void fordJohnsonMergeInsertSort(std::vector<int>& vec, std::size_t left, std::size_t right);
    static void fordJohnsonMergeInsertSort(std::deque<int>& deq, std::size_t left, std::size_t right);
    static void merge(std::vector<int>& vec, std::size_t left, std::size_t mid, std::size_t right);
    static void merge(std::deque<int>& deq, std::size_t left, std::size_t mid, std::size_t right);
};

#endif
