#pragma once

#include "rod_cutting.h"
#include <cxxtest/TestSuite.h>

class RodCuttingTest : public CxxTest::TestSuite {
private:
    std::vector<int> prices, sol, opt_sol;
    int profit;
public:
    void setUp() {
        prices = {1,5,8,9,10,17,17,20,24,30};
        sol.clear();
    }

    void tearDown() {
        prices.clear();
    }

    void test_invalid1() {
        profit = rotCutting(-1, prices);
        TS_ASSERT_EQUALS(profit, 0);
    }

    void test_invalid2() {
        profit = rotCutting(0, prices);
        TS_ASSERT_EQUALS(profit, 0);
    }

    void test_normal1() {
        profit = rotCutting(1, prices);
        TS_ASSERT_EQUALS(profit, 1);
    }

    void test_normal2() {
        profit = rotCutting(3, prices);
        TS_ASSERT_EQUALS(profit, 8);
    }

    void test_normal3() {
        profit = rotCutting(5, prices);
        TS_ASSERT_EQUALS(profit, 13);
    }

    void test_normal4() {
        profit = rotCutting(9, prices);
        TS_ASSERT_EQUALS(profit, 25);
    }

    void test_normal5() {
        profit = rotCutting(10, prices);
        TS_ASSERT_EQUALS(profit, 30);
    }

    void test_solution1() {
        profit = rotCutting(9, prices, sol);
        opt_sol = {3, 6};
        assert_equal_vec(sol, opt_sol);
    }

    void test_solution2() {
        profit = rotCutting(10, prices, sol);
        opt_sol = {10};
        assert_equal_vec(sol, opt_sol);
    }

    void assert_equal_vec(const std::vector<int>& a, const std::vector<int>& b) {
        TS_ASSERT_EQUALS(a.size(), b.size());
        for (int i = 0; i < int(a.size()); i++) TS_ASSERT_EQUALS(a[i], b[i]);
    }
};
