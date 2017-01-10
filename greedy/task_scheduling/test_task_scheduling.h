#include "task_scheduling.h"
#include <cxxtest/TestSuite.h>

class TestScheduling: public CxxTest::TestSuite {
private:
    std::vector<std::pair<int, int>> tasks;
    std::vector<int> schd, answer;
    int penalty;
public:
    void test_textbook() {
        tasks = {{4,70}, {2,60}, {4,50}, {3,40}, {1,30}, {4,20}, {6,10}};
        penalty = schedule(tasks, schd);
        answer = {1,3,0,2,6,4,5};
        TS_ASSERT_EQUALS(penalty, 50);
        TS_ASSERT_EQUALS(answer, schd);
    }

    void test_noreject() {
        tasks = {{1,30}, {2,50}, {5,20}, {4,10}, {3,60}, {6,15}};
        penalty = schedule(tasks, schd);
        answer = {0,1,4,3,2,5};
        TS_ASSERT_EQUALS(penalty, 0);
        TS_ASSERT_EQUALS(answer, schd);
    }

    void test_dup() {
        tasks = {{3,50}, {3,50}, {3,50}, {3,50}, {3,50}};
        penalty = schedule(tasks, schd);
        TS_ASSERT_EQUALS(penalty, 100);
    }

    void test_fierce() {
        tasks = {{1,100}, {1,90}, {1,80}, {1,70}, {1,85}, {1,75}, {2,110}};
        penalty = schedule(tasks, schd);
        TS_ASSERT_EQUALS(penalty, 400);
    }
};

