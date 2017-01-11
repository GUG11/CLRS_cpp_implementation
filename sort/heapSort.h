#pragma once
#include "heap.h"


template<typename T>
void quickSort(std::vector<T>& A) {
    quickSort(A, 0, A.size());
}

template<typename T>
void quickSort(std::vector<T>& A, int lo, int hi) {
    lo = std::max(0, lo);
    hi = std::min(int(A.size()), hi);
    std::vector<T> tmp(A.begin() + lo, A.begin() + hi);
    MaxHeap<T> heap{tmp};
    for (int i = hi - 1; lo <= i; i--) {
        A[i] = heap.pop();
    }
}
