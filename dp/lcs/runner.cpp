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
bool suite_LCSTest_init = false;
#include "lcs_tests.h"

static LCSTest suite_LCSTest;

static CxxTest::List Tests_LCSTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_LCSTest( "lcs_tests.h", 6, "LCSTest", suite_LCSTest, Tests_LCSTest );

static class TestDescription_suite_LCSTest_test_gene : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_LCSTest_test_gene() : CxxTest::RealTestDescription( Tests_LCSTest, suiteDescription_LCSTest, 12, "test_gene" ) {}
 void runTest() { suite_LCSTest.test_gene(); }
} testDescription_suite_LCSTest_test_gene;

static class TestDescription_suite_LCSTest_test_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_LCSTest_test_empty() : CxxTest::RealTestDescription( Tests_LCSTest, suiteDescription_LCSTest, 19, "test_empty" ) {}
 void runTest() { suite_LCSTest.test_empty(); }
} testDescription_suite_LCSTest_test_empty;

static class TestDescription_suite_LCSTest_test_normal : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_LCSTest_test_normal() : CxxTest::RealTestDescription( Tests_LCSTest, suiteDescription_LCSTest, 24, "test_normal" ) {}
 void runTest() { suite_LCSTest.test_normal(); }
} testDescription_suite_LCSTest_test_normal;

static class TestDescription_suite_LCSTest_test_ambiguity : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_LCSTest_test_ambiguity() : CxxTest::RealTestDescription( Tests_LCSTest, suiteDescription_LCSTest, 30, "test_ambiguity" ) {}
 void runTest() { suite_LCSTest.test_ambiguity(); }
} testDescription_suite_LCSTest_test_ambiguity;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
