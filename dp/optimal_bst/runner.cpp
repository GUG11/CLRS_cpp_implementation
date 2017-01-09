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
bool suite_TestOptimalBST_init = false;
#include "test_obst.h"

static TestOptimalBST suite_TestOptimalBST;

static CxxTest::List Tests_TestOptimalBST = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestOptimalBST( "test_obst.h", 5, "TestOptimalBST", suite_TestOptimalBST, Tests_TestOptimalBST );

static class TestDescription_suite_TestOptimalBST_test_textbook : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestOptimalBST_test_textbook() : CxxTest::RealTestDescription( Tests_TestOptimalBST, suiteDescription_TestOptimalBST, 7, "test_textbook" ) {}
 void runTest() { suite_TestOptimalBST.test_textbook(); }
} testDescription_suite_TestOptimalBST_test_textbook;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
