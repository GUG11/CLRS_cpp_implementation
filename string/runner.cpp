/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_TestStringMatching_init = false;
#include "test_sm.hpp"

static TestStringMatching suite_TestStringMatching;

static CxxTest::List Tests_TestStringMatching = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestStringMatching( "test_sm.hpp", 4, "TestStringMatching", suite_TestStringMatching, Tests_TestStringMatching );

static class TestDescription_suite_TestStringMatching_test_naive1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestStringMatching_test_naive1() : CxxTest::RealTestDescription( Tests_TestStringMatching, suiteDescription_TestStringMatching, 12, "test_naive1" ) {}
 void runTest() { suite_TestStringMatching.test_naive1(); }
} testDescription_suite_TestStringMatching_test_naive1;

static class TestDescription_suite_TestStringMatching_test_naive2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestStringMatching_test_naive2() : CxxTest::RealTestDescription( Tests_TestStringMatching, suiteDescription_TestStringMatching, 20, "test_naive2" ) {}
 void runTest() { suite_TestStringMatching.test_naive2(); }
} testDescription_suite_TestStringMatching_test_naive2;

static class TestDescription_suite_TestStringMatching_test_naive3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestStringMatching_test_naive3() : CxxTest::RealTestDescription( Tests_TestStringMatching, suiteDescription_TestStringMatching, 28, "test_naive3" ) {}
 void runTest() { suite_TestStringMatching.test_naive3(); }
} testDescription_suite_TestStringMatching_test_naive3;

static class TestDescription_suite_TestStringMatching_test_naive4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestStringMatching_test_naive4() : CxxTest::RealTestDescription( Tests_TestStringMatching, suiteDescription_TestStringMatching, 35, "test_naive4" ) {}
 void runTest() { suite_TestStringMatching.test_naive4(); }
} testDescription_suite_TestStringMatching_test_naive4;

static class TestDescription_suite_TestStringMatching_test_transition_table : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestStringMatching_test_transition_table() : CxxTest::RealTestDescription( Tests_TestStringMatching, suiteDescription_TestStringMatching, 44, "test_transition_table" ) {}
 void runTest() { suite_TestStringMatching.test_transition_table(); }
} testDescription_suite_TestStringMatching_test_transition_table;

static class TestDescription_suite_TestStringMatching_test_fa1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestStringMatching_test_fa1() : CxxTest::RealTestDescription( Tests_TestStringMatching, suiteDescription_TestStringMatching, 58, "test_fa1" ) {}
 void runTest() { suite_TestStringMatching.test_fa1(); }
} testDescription_suite_TestStringMatching_test_fa1;

static class TestDescription_suite_TestStringMatching_test_fa2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestStringMatching_test_fa2() : CxxTest::RealTestDescription( Tests_TestStringMatching, suiteDescription_TestStringMatching, 66, "test_fa2" ) {}
 void runTest() { suite_TestStringMatching.test_fa2(); }
} testDescription_suite_TestStringMatching_test_fa2;

static class TestDescription_suite_TestStringMatching_test_fa3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestStringMatching_test_fa3() : CxxTest::RealTestDescription( Tests_TestStringMatching, suiteDescription_TestStringMatching, 74, "test_fa3" ) {}
 void runTest() { suite_TestStringMatching.test_fa3(); }
} testDescription_suite_TestStringMatching_test_fa3;

static class TestDescription_suite_TestStringMatching_test_fa4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestStringMatching_test_fa4() : CxxTest::RealTestDescription( Tests_TestStringMatching, suiteDescription_TestStringMatching, 81, "test_fa4" ) {}
 void runTest() { suite_TestStringMatching.test_fa4(); }
} testDescription_suite_TestStringMatching_test_fa4;

static class TestDescription_suite_TestStringMatching_test_prefix_table : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestStringMatching_test_prefix_table() : CxxTest::RealTestDescription( Tests_TestStringMatching, suiteDescription_TestStringMatching, 89, "test_prefix_table" ) {}
 void runTest() { suite_TestStringMatching.test_prefix_table(); }
} testDescription_suite_TestStringMatching_test_prefix_table;

static class TestDescription_suite_TestStringMatching_test_kmp1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestStringMatching_test_kmp1() : CxxTest::RealTestDescription( Tests_TestStringMatching, suiteDescription_TestStringMatching, 96, "test_kmp1" ) {}
 void runTest() { suite_TestStringMatching.test_kmp1(); }
} testDescription_suite_TestStringMatching_test_kmp1;

static class TestDescription_suite_TestStringMatching_test_kmp2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestStringMatching_test_kmp2() : CxxTest::RealTestDescription( Tests_TestStringMatching, suiteDescription_TestStringMatching, 104, "test_kmp2" ) {}
 void runTest() { suite_TestStringMatching.test_kmp2(); }
} testDescription_suite_TestStringMatching_test_kmp2;

static class TestDescription_suite_TestStringMatching_test_kmp3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestStringMatching_test_kmp3() : CxxTest::RealTestDescription( Tests_TestStringMatching, suiteDescription_TestStringMatching, 112, "test_kmp3" ) {}
 void runTest() { suite_TestStringMatching.test_kmp3(); }
} testDescription_suite_TestStringMatching_test_kmp3;

static class TestDescription_suite_TestStringMatching_test_kmp4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestStringMatching_test_kmp4() : CxxTest::RealTestDescription( Tests_TestStringMatching, suiteDescription_TestStringMatching, 119, "test_kmp4" ) {}
 void runTest() { suite_TestStringMatching.test_kmp4(); }
} testDescription_suite_TestStringMatching_test_kmp4;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
