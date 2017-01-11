#pragma once

#include <vector>
#include <algorithm>

template<typename T>
void heapSort(std::vector<T>& A) {
    heapSort(A, 0, A.size());
}

template<typename T>
void heapSort(std::vector<T>& A, int lo, int hi) {
    lo = std::max(0, lo);
    hi = std::min(int(A.size()), hi);
    if (lo < hi - 1) {
        int pivot = A[hi-1], j = lo;
        for (int i = lo; i < hi - 1; i++) {
            if (A[i] < pivot) std::swap(A[j++], A[i]);
        }
        std::swap(A[hi-1], A[j]);
        heapSort(A, lo, j);
        heapSort(A, j + 1, hi);
    }
}
