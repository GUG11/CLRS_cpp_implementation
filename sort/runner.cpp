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
bool suite_TestHeap_init = false;
#include "test_heap.h"

static TestHeap suite_TestHeap;

static CxxTest::List Tests_TestHeap = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestHeap( "test_heap.h", 5, "TestHeap", suite_TestHeap, Tests_TestHeap );

static class TestDescription_suite_TestHeap_test_max : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestHeap_test_max() : CxxTest::RealTestDescription( Tests_TestHeap, suiteDescription_TestHeap, 13, "test_max" ) {}
 void runTest() { suite_TestHeap.test_max(); }
} testDescription_suite_TestHeap_test_max;

static class TestDescription_suite_TestHeap_test_pop : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestHeap_test_pop() : CxxTest::RealTestDescription( Tests_TestHeap, suiteDescription_TestHeap, 22, "test_pop" ) {}
 void runTest() { suite_TestHeap.test_pop(); }
} testDescription_suite_TestHeap_test_pop;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
