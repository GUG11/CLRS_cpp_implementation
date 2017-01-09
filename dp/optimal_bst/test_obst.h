#include <cxxtest/TestSuite.h>
#include "optimal_bst.h"
#include <vector>

class TestOptimalBST : public CxxTest::TestSuite {
public:
    void test_textbook() {
        std::vector<double> p{0.15, 0.1, 0.05, 0.1, 0.2}, q{0.05, 0.1, 0.05, 0.05, 0.05, 0.1};
        double res = optimalBST(p, q);
        TS_ASSERT_EQUALS(res, 2.75);
    }
};
