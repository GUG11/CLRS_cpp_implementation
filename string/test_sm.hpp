#include <cxxtest/TestSuite.h>
#include "string_matching.h"

class TestStringMatching : public CxxTest::TestSuite {
private:

public:
    void setUp() {}

    void tearDown() {}

    void test_naive1() {  // textbook
        std::string T = "abcabaabcabac";
        std::string P = "abaa";
        std::vector<int> pos = naiveStringMatching(T, P);
        std::vector<int> answer = {3};
        TS_ASSERT_EQUALS(pos, answer);       
    }

    void test_naive2() {  // multiple matches
        std::string T = "aaaabaaaabaaabaaaaabaaaab";
        std::string P = "aaaab";
        std::vector<int> pos = naiveStringMatching(T, P);
        std::vector<int> answer = {0, 5, 15, 20};
        TS_ASSERT_EQUALS(pos, answer);       
    }

    void test_naive3() {   // no match
        std::string T = "abacdeftzaba";
        std::string P = "cdefx";
        std::vector<int> pos = naiveStringMatching(T, P);
        TS_ASSERT(pos.empty());
    }

    void test_naive4() {   // two matches overlap
        std::string T = "aaaaaaaaa";
        std::string P = "aaaa";
        std::vector<int> pos = naiveStringMatching(T, P);
        std::vector<int> answer = {0, 1, 2, 3, 4, 5};
        TS_ASSERT_EQUALS(pos, answer);       
    }


    void test_transition_table() {
        std::string P = "ababaca";
        FATable delta = computeTransitionFunction(P);
        FATable answer = {{{'a', 1}, {'b', 0}, {'c', 0}}, 
            {{'a', 1}, {'b', 2}, {'c', 0}},
            {{'a', 3}, {'b', 0}, {'c', 0}},
            {{'a', 1}, {'b', 4}, {'c', 0}},
            {{'a', 5}, {'b', 0}, {'c', 0}},
            {{'a', 1}, {'b', 4}, {'c', 6}},
            {{'a', 7}, {'b', 0}, {'c', 0}},
            {{'a', 1}, {'b', 2}, {'c', 0}}};
        TS_ASSERT_EQUALS(delta, answer);
    }

    void test_fa1() {
        std::string T = "abcabaabcabac";
        std::string P = "abaa";
        std::vector<int> pos = FAMatching(T, P);
        std::vector<int> answer = {3};
        TS_ASSERT_EQUALS(pos, answer);       
    }

    void test_fa2() {
        std::string T = "aaaabaaaabaaabaaaaabaaaab";
        std::string P = "aaaab";
        std::vector<int> pos = FAMatching(T, P);
        std::vector<int> answer = {0, 5, 15, 20};
        TS_ASSERT_EQUALS(pos, answer);       
    }

    void test_fa3() {
        std::string T = "abacdeftzaba";
        std::string P = "cdefx";
        std::vector<int> pos = FAMatching(T, P);
        TS_ASSERT(pos.empty());
    }

    void test_fa4() {   // two matches overlap
        std::string T = "aaaaaaaaa";
        std::string P = "aaaa";
        std::vector<int> pos = FAMatching(T, P);
        std::vector<int> answer = {0, 1, 2, 3, 4, 5};
        TS_ASSERT_EQUALS(pos, answer);       
    }

    void test_prefix_table() {
        std::string P = "ababaca";
        std::vector<int> pt = buildPrefixTable(P); 
        std::vector<int> answer = {-1, -1, 0, 1, 2, -1, 0};
        TS_ASSERT_EQUALS(pt, answer);
    }

    void test_kmp1() {  // textbook
        std::string T = "abcabaabcabac";
        std::string P = "abaa";
        std::vector<int> pos = KMP(T, P);
        std::vector<int> answer = {3};
        TS_ASSERT_EQUALS(pos, answer);       
    }

    void test_kmp2() {  // multiple matches
        std::string T = "aaaabaaaabaaabaaaaabaaaab";
        std::string P = "aaaab";
        std::vector<int> pos = KMP(T, P);
        std::vector<int> answer = {0, 5, 15, 20};
        TS_ASSERT_EQUALS(pos, answer);       
    }

    void test_kmp3() {   // no match
        std::string T = "abacdeftzaba";
        std::string P = "cdefx";
        std::vector<int> pos = KMP(T, P);
        TS_ASSERT(pos.empty());
    }

    void test_kmp4() {   // two matches overlap
        std::string T = "aaaaaaaaa";
        std::string P = "aaaa";
        std::vector<int> pos = KMP(T, P);
        std::vector<int> answer = {0, 1, 2, 3, 4, 5};
        TS_ASSERT_EQUALS(pos, answer);       
    }


};
