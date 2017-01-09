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
bool suite_MatrixChainTest_init = false;
#include "test_mc.h"

static MatrixChainTest suite_MatrixChainTest;

static CxxTest::List Tests_MatrixChainTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MatrixChainTest( "test_mc.h", 4, "MatrixChainTest", suite_MatrixChainTest, Tests_MatrixChainTest );

static class TestDescription_suite_MatrixChainTest_test_single : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MatrixChainTest_test_single() : CxxTest::RealTestDescription( Tests_MatrixChainTest, suiteDescription_MatrixChainTest, 9, "test_single" ) {}
 void runTest() { suite_MatrixChainTest.test_single(); }
} testDescription_suite_MatrixChainTest_test_single;

static class TestDescription_suite_MatrixChainTest_test_seq1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MatrixChainTest_test_seq1() : CxxTest::RealTestDescription( Tests_MatrixChainTest, suiteDescription_MatrixChainTest, 15, "test_seq1" ) {}
 void runTest() { suite_MatrixChainTest.test_seq1(); }
} testDescription_suite_MatrixChainTest_test_seq1;

static class TestDescription_suite_MatrixChainTest_test_seq2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MatrixChainTest_test_seq2() : CxxTest::RealTestDescription( Tests_MatrixChainTest, suiteDescription_MatrixChainTest, 21, "test_seq2" ) {}
 void runTest() { suite_MatrixChainTest.test_seq2(); }
} testDescription_suite_MatrixChainTest_test_seq2;

static class TestDescription_suite_MatrixChainTest_test_sol1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MatrixChainTest_test_sol1() : CxxTest::RealTestDescription( Tests_MatrixChainTest, suiteDescription_MatrixChainTest, 27, "test_sol1" ) {}
 void runTest() { suite_MatrixChainTest.test_sol1(); }
} testDescription_suite_MatrixChainTest_test_sol1;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
