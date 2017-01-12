#pragma once

#include "linkedlist.h"
#include "stack.h"
#include "queue.h"
#include <cxxtest/TestSuite.h>
#include <algorithm>
#include <vector>

class TestList : public CxxTest::TestSuite {
public:
    void test_size_empty() {
        List<int> l;
        TS_ASSERT(l.empty());
        l.push_front(1);
        TS_ASSERT(!l.empty());
        l.push_back(2);
        TS_ASSERT_EQUALS(l.size(), 2);
        l.pop_back();
        TS_ASSERT_EQUALS(l.size(), 1);
        l.pop_back();
        TS_ASSERT(l.empty());
    }

    void test_front() {
        List<int> l;
        std::vector<int> V1{5,4,3,2,1};
        for (auto e: V1) {
            l.push_front(e);
            TS_ASSERT_EQUALS(l.front(), e);
        }
        std::reverse(V1.begin(), V1.end());
        for (auto e: V1) {
            TS_ASSERT_EQUALS(l.pop_front(), e);
        }
    }

    void test_back() {
        List<int> l;
        std::vector<int> V2{6,7,8,9,10};
        for (auto e: V2) {
            l.push_back(e);
            TS_ASSERT_EQUALS(l.back(), e);
        }
        std::reverse(V2.begin(), V2.end());
        for (auto e: V2) {
            TS_ASSERT_EQUALS(l.pop_back(), e);
        }
    }

    void test_stack() {
        Stack<int> S;
        std::vector<int> V1{1,2,3,4,5};
        for (auto e: V1) {
            S.push(e);
            TS_ASSERT_EQUALS(S.top(), e);
        }
        TS_ASSERT(!S.empty());
        TS_ASSERT_EQUALS(S.size(), 5);
        std::reverse(V1.begin(), V1.end());
        for (auto e: V1) {
            TS_ASSERT_EQUALS(S.pop(), e);
        }
        TS_ASSERT(S.empty());
    }

    void test_queue() {
        Queue<int> Q;
        std::vector<int> V2{6,7,8,9,10};
        for (auto e: V2) {
            Q.push(e);
            TS_ASSERT_EQUALS(Q.front(), V2[0]);
        }
        TS_ASSERT(!Q.empty());
        TS_ASSERT_EQUALS(Q.size(), 5);
        for (auto e: V2) {
            TS_ASSERT_EQUALS(Q.pop(), e);
        }
        TS_ASSERT(Q.empty());
    }
};
