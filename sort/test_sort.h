#pragma once
#include <cxxtest/TestSuite.h>
#include "sort.h"
#include <cstdlib>
#include <random>

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

    void test_countsort1() {
        V = {0,1,4,3,2,2,4,2,1};
        countingSort(V);
        TS_ASSERT_EQUALS(V.size(), 9);
        TS_ASSERT(nonDecreasing(V));
    }

    void test_countsort_all_same() {
        V = std::vector<int>(50, 2);
        std::vector<int> R{V};
        countingSort(V);
        TS_ASSERT_EQUALS(V, R);
    }

    void test_countsort_random() {
        int hi = 100;
        V.clear();
        for (int i = 0; i < 10000; i++) V.push_back(rand() % hi);
        countingSort(V);
        TS_ASSERT_EQUALS(V.size(), 10000);
        TS_ASSERT(nonDecreasing(V));
    }

    void test_bucketsort1() {
        std::vector<double> R{0.1, 0.2, 0.11, 0.05, 0.99, 0.86, 0.45};
        bucketSort(R);
        TS_ASSERT_EQUALS(R.size(), 7);
        TS_ASSERT(nonDecreasing(R));
    }

    void test_bucketsort_all_same() {
        std::vector<double> R(50, 0.1), T = R;
        bucketSort(R);
        TS_ASSERT_EQUALS(R, T);
    }

    void test_bucketsort_random() {
        std::vector<double> R(10000);
        std::default_random_engine generator(1);
        std::uniform_real_distribution<double> dist(0.0, 1.0);
        for (int i = 0; i < 10000; i++) R.push_back(dist(generator));
        bucketSort(R);
        TS_ASSERT(nonDecreasing(R));
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

    template<typename T>
    bool nonDecreasing(const std::vector<T>& V) {
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
