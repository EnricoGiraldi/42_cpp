#include "PmergeMe.hpp"
#include <algorithm> 

void PmergeMe::mergeInsertSort(std::vector<int>& vec) {
    fordJohnsonMergeInsertSort(vec, 0, vec.size() - 1);
}

void PmergeMe::mergeInsertSort(std::deque<int>& deq) {
    fordJohnsonMergeInsertSort(deq, 0, deq.size() - 1);
}

void PmergeMe::fordJohnsonMergeInsertSort(std::vector<int>& vec, std::size_t left, std::size_t right) {
    if (left >= right) return;

    if (right - left + 1 <= 4) {
        std::sort(vec.begin() + left, vec.begin() + right + 1);
        return;
    }

    std::size_t mid = left + (right - left) / 2;
    fordJohnsonMergeInsertSort(vec, left, mid);
    fordJohnsonMergeInsertSort(vec, mid + 1, right);
    merge(vec, left, mid, right);
}

void PmergeMe::fordJohnsonMergeInsertSort(std::deque<int>& deq, std::size_t left, std::size_t right) {
    if (left >= right) return;

    if (right - left + 1 <= 4) {
        std::deque<int> subDeque(deq.begin() + left, deq.begin() + right + 1);
        std::sort(subDeque.begin(), subDeque.end());
        std::copy(subDeque.begin(), subDeque.end(), deq.begin() + left);
        return;
    }

    std::size_t mid = left + (right - left) / 2;
    fordJohnsonMergeInsertSort(deq, left, mid);
    fordJohnsonMergeInsertSort(deq, mid + 1, right);
    merge(deq, left, mid, right);
}

void PmergeMe::merge(std::vector<int>& vec, std::size_t left, std::size_t mid, std::size_t right) {
    std::vector<int> leftPart(vec.begin() + left, vec.begin() + mid + 1);
    std::vector<int> rightPart(vec.begin() + mid + 1, vec.begin() + right + 1);

    std::vector<int>::iterator leftIt = leftPart.begin();
    std::vector<int>::iterator rightIt = rightPart.begin();
    std::vector<int>::iterator vecIt = vec.begin() + left;

    while (leftIt != leftPart.end() && rightIt != rightPart.end()) {
        if (*leftIt <= *rightIt) {
            *vecIt++ = *leftIt++;
        } else {
            *vecIt++ = *rightIt++;
        }
    }

    std::copy(leftIt, leftPart.end(), vecIt);
    std::copy(rightIt, rightPart.end(), vecIt);
}

void PmergeMe::merge(std::deque<int>& deq, std::size_t left, std::size_t mid, std::size_t right) {
    std::deque<int> leftPart(deq.begin() + left, deq.begin() + mid + 1);
    std::deque<int> rightPart(deq.begin() + mid + 1, deq.begin() + right + 1);

    std::deque<int>::iterator leftIt = leftPart.begin();
    std::deque<int>::iterator rightIt = rightPart.begin();
    std::deque<int>::iterator deqIt = deq.begin() + left;

    while (leftIt != leftPart.end() && rightIt != rightPart.end()) {
        if (*leftIt <= *rightIt) {
            *deqIt++ = *leftIt++;
        } else {
            *deqIt++ = *rightIt++;
        }
    }

    std::copy(leftIt, leftPart.end(), deqIt);
    std::copy(rightIt, rightPart.end(), deqIt);
}
