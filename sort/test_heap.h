#pragma once
#include <cxxtest/TestSuite.h>
#include "heap.h"

class TestHeap : public CxxTest::TestSuite {
private:
    MaxHeap<int> heap;
public:
    void tearDown() {
        while (!heap.empty()) heap.pop();
    }

    void test_max() {
        std::vector<int> V(100);
        std::iota(V.begin(), V.end(), 0);
        for (auto e : V) {
            heap.push(e);
            TS_ASSERT_EQUALS(heap.top(), e);
        }
    }

    void test_pop() {
        std::vector<int> V(100);
        std::iota(V.begin(), V.end(), 0);
        heap = MaxHeap<int>(V);
        for (auto it = V.rbegin(); it != V.rend(); it++) {
            TS_ASSERT_EQUALS(heap.pop(), *it);
        }
    }
};
