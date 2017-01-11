#pragma once
#include <vector>

/**
 * All intervals in sort algorithms are left closed and right open [lo,hi)
 * */

// O(n^2) sort
// O(n*logn) sort
template<typename T>
void mergeSort(std::vector<T>& A);

template<typename T>
void mergeSort(std::vector<T>& A, int lo, int hi);

template<typename T>
void heapSort(std::vector<T>& A);

template<typename T>
void heapSort(std::vector<T>& A, int lo, int hi);

template<typename T>
void quickSort(std::vector<T>& A);

template<typename T>
void quickSort(std::vector<T>& A, int lo, int hi);

#include "mergeSort.h"
#include "heapSort.h"
#include "quickSort.h"

// O(n) sort
