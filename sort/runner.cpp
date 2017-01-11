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
bool suite_TestSort_init = false;
#include "test_sort.h"

static TestSort suite_TestSort;

static CxxTest::List Tests_TestSort = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestSort( "test_sort.h", 5, "TestSort", suite_TestSort, Tests_TestSort );

static class TestDescription_suite_TestSort_test_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestSort_test_empty() : CxxTest::RealTestDescription( Tests_TestSort, suiteDescription_TestSort, 10, "test_empty" ) {}
 void runTest() { suite_TestSort.test_empty(); }
} testDescription_suite_TestSort_test_empty;

static class TestDescription_suite_TestSort_test_singleton : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestSort_test_singleton() : CxxTest::RealTestDescription( Tests_TestSort, suiteDescription_TestSort, 20, "test_singleton" ) {}
 void runTest() { suite_TestSort.test_singleton(); }
} testDescription_suite_TestSort_test_singleton;

static class TestDescription_suite_TestSort_test_ascending : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestSort_test_ascending() : CxxTest::RealTestDescription( Tests_TestSort, suiteDescription_TestSort, 33, "test_ascending" ) {}
 void runTest() { suite_TestSort.test_ascending(); }
} testDescription_suite_TestSort_test_ascending;

static class TestDescription_suite_TestSort_test_descending : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestSort_test_descending() : CxxTest::RealTestDescription( Tests_TestSort, suiteDescription_TestSort, 44, "test_descending" ) {}
 void runTest() { suite_TestSort.test_descending(); }
} testDescription_suite_TestSort_test_descending;

static class TestDescription_suite_TestSort_test_random10 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestSort_test_random10() : CxxTest::RealTestDescription( Tests_TestSort, suiteDescription_TestSort, 57, "test_random10" ) {}
 void runTest() { suite_TestSort.test_random10(); }
} testDescription_suite_TestSort_test_random10;

static class TestDescription_suite_TestSort_test_random100 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestSort_test_random100() : CxxTest::RealTestDescription( Tests_TestSort, suiteDescription_TestSort, 61, "test_random100" ) {}
 void runTest() { suite_TestSort.test_random100(); }
} testDescription_suite_TestSort_test_random100;

static class TestDescription_suite_TestSort_test_random1000 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestSort_test_random1000() : CxxTest::RealTestDescription( Tests_TestSort, suiteDescription_TestSort, 65, "test_random1000" ) {}
 void runTest() { suite_TestSort.test_random1000(); }
} testDescription_suite_TestSort_test_random1000;

static class TestDescription_suite_TestSort_test_random10000 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestSort_test_random10000() : CxxTest::RealTestDescription( Tests_TestSort, suiteDescription_TestSort, 69, "test_random10000" ) {}
 void runTest() { suite_TestSort.test_random10000(); }
} testDescription_suite_TestSort_test_random10000;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
