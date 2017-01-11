#pragma once

#include <vector>
#include <algorithm>

template<typename T>
void mergeSort(std::vector<T>& A) {
    mergeSort(A, 0, A.size());
}

template<typename T>
void mergeSort(std::vector<T>& A, int lo, int hi) {
    lo = std::max(0, lo);
    hi = std::min(int(A.size()), hi);
    if (lo < hi - 1) {
        std::vector<T> L, R;
        int mid = (lo + hi) / 2, i = lo, j = mid, k = lo;
        mergeSort(A, lo, mid);
        mergeSort(A, mid, hi);
        L.assign(A.begin() + lo, A.begin() + mid);
        R.assign(A.begin() + mid, A.begin() + hi);
        while (i < mid || j < hi) {
            if (i == mid || (j < hi && L[i - lo] > R[j - mid])) {
                A[k] = R[j - mid];
                j++;
            } else {
                A[k] = L[i - lo];
                i++;
            }
            k++; 
        }
    }
}
