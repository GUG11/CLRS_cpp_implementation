/**
 * RBTree tests
 * Unit test using CxxTest
 * cxxtestgen --error-printer -o runner.cpp rbt_tests.h
 * g++ -o runner runner.cpp
 * ./runner
 * */

#include <cxxtest/TestSuite.h>
#include "visitor.h"
#include "rbtree.h"
#include <vector>


class RBTreeTest : public CxxTest::TestSuite {
private:
    std::vector<int> V;
public:
    void setUp() {
        for (int i = 0; i < 10; i++) V.push_back(i);
    }

    void tearDown() {
        V.clear();
    }

    void testInsertDelete() {
        RBTree<int> rbt;
        BSTNode<int> *x;
        for (int e: V) {
            x = rbt.insert(e);
            TS_ASSERT(x);
            TS_ASSERT_EQUALS(x->key, e);
            x = rbt.search(e);
            TS_ASSERT(x);
            TS_ASSERT_EQUALS(x->key, e);
        }
        for (int e: V) {
            x = rbt.deleteNode(e);
            TS_ASSERT(x);
            TS_ASSERT_EQUALS(x->key, e);
            delete x;
            x = rbt.search(e);
            TS_ASSERT(!x);
        }
    }
};
