#pragma once
#include <cxxtest/TestSuite.h>
#include "sort.h"

class TestSort : public CxxTest::TestSuite {
private:
    std::vector<int> V, V2;

public:
    void test_empty() {
        V = {};
        mergeSort(V2 = V);
        TS_ASSERT(V2.empty());
        heapSort(V2 = V);
        TS_ASSERT(V2.empty());
        quickSort(V2 = V);
        TS_ASSERT(V2.empty());
    }

    void test_singleton() {
        V = {10};
        mergeSort(V2 = V);
        TS_ASSERT_EQUALS(V2.size(), 1);
        TS_ASSERT_EQUALS(V2[0], 10);
        heapSort(V2 = V);
        TS_ASSERT_EQUALS(V2.size(), 1);
        TS_ASSERT_EQUALS(V2[0], 10);
        quickSort(V2 = V);
        TS_ASSERT_EQUALS(V2.size(), 1);
        TS_ASSERT_EQUALS(V2[0], 10);
    }

    void test_ascending() {
        V.resize(100);
        std::iota(V.begin(), V.end(), 0);
        mergeSort(V2 = V);
        TS_ASSERT_EQUALS(V2, V);
        heapSort(V2 = V);
        TS_ASSERT_EQUALS(V2, V);
        quickSort(V2 = V);
        TS_ASSERT_EQUALS(V2, V);
    }

    void test_descending() {
        V.resize(100);
        std::iota(V.begin(), V.end(), 0);
        std::vector<int> R{V};
        std::reverse(R.begin(), R.end());
        mergeSort(V2 = R);
        TS_ASSERT_EQUALS(V2, V);
        heapSort(V2 = R);
        TS_ASSERT_EQUALS(V2, V);
        quickSort(V2 = R);
        TS_ASSERT_EQUALS(V2, V);
    }

    void test_random10() {
        test_random(10);
    }

    void test_random100() {
        test_random(100);
    }

    void test_random1000() {
        test_random(1000);
    }

    void test_random10000() {
        test_random(10000);
    }

    void test_random(int n) {
        V.resize(n);
        std::iota(V.begin(), V.end(), 0);
        std::vector<int> R{V};
        std::random_shuffle(R.begin(), R.end());
        mergeSort(V2 = R);
        TS_ASSERT_EQUALS(V2, V);
        heapSort(V2 = R);
        TS_ASSERT_EQUALS(V2, V);
        quickSort(V2 = R);
        TS_ASSERT_EQUALS(V2, V);
    }

    bool nonDecreasing(const std::vector<int>& V) {
        int n = V.size();
        bool res = true;
        for (int i = 1; i < n; i++) {
            if (V[i] < V[i-1]) {
                res = false;
                break;
            }
        }
        return res;
    }
};
