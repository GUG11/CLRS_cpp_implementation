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
bool suite_TestScheduling_init = false;
#include "test_task_scheduling.h"

static TestScheduling suite_TestScheduling;

static CxxTest::List Tests_TestScheduling = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestScheduling( "test_task_scheduling.h", 4, "TestScheduling", suite_TestScheduling, Tests_TestScheduling );

static class TestDescription_suite_TestScheduling_test_textbook : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestScheduling_test_textbook() : CxxTest::RealTestDescription( Tests_TestScheduling, suiteDescription_TestScheduling, 10, "test_textbook" ) {}
 void runTest() { suite_TestScheduling.test_textbook(); }
} testDescription_suite_TestScheduling_test_textbook;

static class TestDescription_suite_TestScheduling_test_noreject : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestScheduling_test_noreject() : CxxTest::RealTestDescription( Tests_TestScheduling, suiteDescription_TestScheduling, 18, "test_noreject" ) {}
 void runTest() { suite_TestScheduling.test_noreject(); }
} testDescription_suite_TestScheduling_test_noreject;

static class TestDescription_suite_TestScheduling_test_dup : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestScheduling_test_dup() : CxxTest::RealTestDescription( Tests_TestScheduling, suiteDescription_TestScheduling, 26, "test_dup" ) {}
 void runTest() { suite_TestScheduling.test_dup(); }
} testDescription_suite_TestScheduling_test_dup;

static class TestDescription_suite_TestScheduling_test_fierce : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestScheduling_test_fierce() : CxxTest::RealTestDescription( Tests_TestScheduling, suiteDescription_TestScheduling, 32, "test_fierce" ) {}
 void runTest() { suite_TestScheduling.test_fierce(); }
} testDescription_suite_TestScheduling_test_fierce;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
