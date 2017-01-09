#include "activity.h"
#include <cxxtest/TestSuite.h>

class TestActivity : public CxxTest::TestSuite {
private:
    std::vector<std::pair<int, int>> intervals;
    std::vector<int> S, answer;

public:
    void test_textbook() {
        intervals = {{1,4}, {3,5}, {0,6}, {5,7}, {3,9}, {5,9}, {6,10}, {8,11}, {8,12}, {2,14}, {12,16}};
        std::sort(intervals.begin(), intervals.end(), cmp);
        S = activity_selection(intervals);
        answer = {0,3,7,10};
        TS_ASSERT_EQUALS(S, answer);
    }


    void test_empty() {
        intervals = {};
        std::sort(intervals.begin(), intervals.end(), cmp);
        S = activity_selection(intervals);
        TS_ASSERT(S.empty());
    }

    void test_singleton() {
        intervals = {{1,4}};
        std::sort(intervals.begin(), intervals.end(), cmp);
        S = activity_selection(intervals);
        answer = {0};
        TS_ASSERT_EQUALS(S, answer);
    }

    void test_no_conflicts() {
        intervals = {{1,3},{3,5},{6,7},{9,10},{11,15},{15,16},{16,19}};
        std::sort(intervals.begin(), intervals.end(), cmp);
        S = activity_selection(intervals);
        answer = {0,1,2,3,4,5,6};
        TS_ASSERT_EQUALS(S, answer);
    }

    void test_long_act() {
        intervals = {{1,20},{3,5},{6,7},{9,10},{11,15},{15,16}};
        std::sort(intervals.begin(), intervals.end(), cmp);
        S = activity_selection(intervals);
        answer = {0,1,2,3,4};
        TS_ASSERT_EQUALS(S, answer);
    }
};
