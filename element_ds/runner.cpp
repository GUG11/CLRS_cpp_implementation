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
bool suite_TestList_init = false;
#include "test_list.h"

static TestList suite_TestList;

static CxxTest::List Tests_TestList = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestList( "test_list.h", 10, "TestList", suite_TestList, Tests_TestList );

static class TestDescription_suite_TestList_test_size_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestList_test_size_empty() : CxxTest::RealTestDescription( Tests_TestList, suiteDescription_TestList, 12, "test_size_empty" ) {}
 void runTest() { suite_TestList.test_size_empty(); }
} testDescription_suite_TestList_test_size_empty;

static class TestDescription_suite_TestList_test_front : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestList_test_front() : CxxTest::RealTestDescription( Tests_TestList, suiteDescription_TestList, 25, "test_front" ) {}
 void runTest() { suite_TestList.test_front(); }
} testDescription_suite_TestList_test_front;

static class TestDescription_suite_TestList_test_back : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestList_test_back() : CxxTest::RealTestDescription( Tests_TestList, suiteDescription_TestList, 38, "test_back" ) {}
 void runTest() { suite_TestList.test_back(); }
} testDescription_suite_TestList_test_back;

static class TestDescription_suite_TestList_test_stack : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestList_test_stack() : CxxTest::RealTestDescription( Tests_TestList, suiteDescription_TestList, 51, "test_stack" ) {}
 void runTest() { suite_TestList.test_stack(); }
} testDescription_suite_TestList_test_stack;

static class TestDescription_suite_TestList_test_queue : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestList_test_queue() : CxxTest::RealTestDescription( Tests_TestList, suiteDescription_TestList, 67, "test_queue" ) {}
 void runTest() { suite_TestList.test_queue(); }
} testDescription_suite_TestList_test_queue;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
