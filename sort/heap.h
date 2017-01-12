#pragma once

#include <vector>
#include <algorithm>

/**
 *                16
 *             /      \
 *          14          10
 *        /    \      /    \
 *       8      7    9      3
 *      / \    /
 *      2 4    1
 *
 *      16,14,10,8,7,9,3,2,4,1
 *      0  1  2  3 4 5 6 7 8 9
 *
 * */
template<typename T>
class MaxHeap {
private:
    std::vector<T> V;
    inline int parent(int i) {return (i-1)/2;}
    inline int left(int i) {return 2 * i + 1;}
    inline int right(int i) {return 2 * i + 2;}
    void percolateUp(int i);
public:
    MaxHeap() {}
    MaxHeap(std::vector<T>& A);
    void maxHeapify(int i);
    T pop();
    T top() const {return V[0];}
    int size() const {return V.size();}
    bool empty() const {return V.size() == 0;}
    void push(T& key);
};

template<typename T>
void MaxHeap<T>::maxHeapify(int i) {
    int l = left(i), r = right(i), largest = i;
    if (l < int(V.size()) && V[largest] < V[l]) largest = l;
    if (r < int(V.size()) && V[largest] < V[r]) largest = r;
    if (largest != i) {
        std::swap(V[i], V[largest]);
        maxHeapify(largest);
    }
}

template<typename T>
MaxHeap<T>::MaxHeap(std::vector<T>& A) {
    V.assign(A.begin(), A.end());
    for (int i = parent(V.size() - 1); -1 < i; i--) maxHeapify(i);
}

template<typename T>
T MaxHeap<T>::pop() {
    T tmp = V[0];
    V[0] = V.back();
    V.pop_back();
    maxHeapify(0);
    return tmp;
}

template<typename T>
void MaxHeap<T>::percolateUp(int i) {
    while (0 < i && V[parent(i)] < V[i]) {
        std::swap(V[i], V[parent(i)]);
        i = parent(i);
    }
}

template<typename T>
void MaxHeap<T>::push(T& key) {
    V.push_back(key);
    percolateUp(V.size()-1);
}
