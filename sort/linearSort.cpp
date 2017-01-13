#include "sort.h"
#include <list>

void countingSort(std::vector<int>& A) {
    std::vector<int> cumCount(A.size() + 1, 0), B(A);   
    for (auto e: A) cumCount[e]++;
    for (int i = 1; i < int(cumCount.size()); i++) cumCount[i] += cumCount[i-1];
    for (int j = B.size() - 1; -1 < j; j--) A[--cumCount[B[j]]] = B[j];
}

void bucketSort(std::vector<double>& A) {
    int n = A.size();
    std::vector<std::list<double>> B(n);
    for (auto e: A) B[int(e * n)].push_back(e);
    for (auto& b: B) b.sort();
    A.clear();
    for (auto b: B) A.insert(A.end(), b.begin(), b.end()); 
}
