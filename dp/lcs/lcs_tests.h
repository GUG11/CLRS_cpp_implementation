#pragma once

#include <cxxtest/TestSuite.h>
#include "lcs.h"

class LCSTest : public CxxTest::TestSuite {
public:
    /**
     * ACCGGTCGAGTGCGCGGAA GCCG  GC C G AA
     *     GTCGT T CG G AATGCCGTTGCTCTGTAAA
     * */
    void test_gene() {
        std::string S1{"ACCGGTCGAGTGCGCGGAAGCCGGCCGAA"}, S2{"GTCGTTCGGAATGCCGTTGCTCTGTAAA"};
        std::string Z_alo, Z_ref{"GTCGTCGGAAGCCGGCCGAA"};
        Z_alo = lcs(S1, S2);
        TS_ASSERT_EQUALS(Z_alo, Z_ref);
    }

    void test_empty() {
        std::string S1, S2, Z = lcs(S1, S2);
        TS_ASSERT(Z.empty());
    }

    void test_normal() {
        std::string S1{"BDCABA"}, S2{"ABCBDAB"};
        std::string Z = lcs(S1, S2);
        TS_ASSERT(Z == "BCBA" || Z == "BDAB");
    }

    void test_ambiguity() {
        std::string S1{"aabbaaaaab"}, S2{"aaaab"};
        TS_ASSERT_EQUALS(lcs(S1, S2), "aaaab");
    }
};
