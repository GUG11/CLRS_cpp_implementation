#include "matrix_chain.h"
#include <cxxtest/TestSuite.h>

class MatrixChainTest : public CxxTest::TestSuite {
private:
    int n;

public:
    void test_single() {
        std::vector<std::pair<int, int>> As = {{30,35}};
        n = matrix_chain(As);
        TS_ASSERT_EQUALS(n, 0);
    }

    void test_seq1() {
        std::vector<std::pair<int, int>> As = {{35,15}, {15,5}, {5,10}, {10,20}};
        n = matrix_chain(As);
        TS_ASSERT_EQUALS(n, 7125);
    }

    void test_seq2() {
        std::vector<std::pair<int, int>> As = {{30,35}, {35,15}, {15,5}, {5,10}, {10,20}, {20,25}};
        n = matrix_chain(As);
        TS_ASSERT_EQUALS(n, 15125);
    }
    
    void test_sol1() {
        std::vector<std::pair<int, int>> As = {{30,35}, {35,15}, {15,5}, {5,10}, {10,20}, {20,25}};
        std::string sol, ref_sol = "((1(23))((45)6))";
        n = matrix_chain(As, sol);
        TS_ASSERT_EQUALS(sol, ref_sol);
    }
};
