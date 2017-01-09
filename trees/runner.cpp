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
bool suite_RBTreeTest_init = false;
#include "rbt_tests.h"

static RBTreeTest suite_RBTreeTest;

static CxxTest::List Tests_RBTreeTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_RBTreeTest( "rbt_tests.h", 15, "RBTreeTest", suite_RBTreeTest, Tests_RBTreeTest );

static class TestDescription_suite_RBTreeTest_testInsertDelete : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_RBTreeTest_testInsertDelete() : CxxTest::RealTestDescription( Tests_RBTreeTest, suiteDescription_RBTreeTest, 27, "testInsertDelete" ) {}
 void runTest() { suite_RBTreeTest.testInsertDelete(); }
} testDescription_suite_RBTreeTest_testInsertDelete;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
