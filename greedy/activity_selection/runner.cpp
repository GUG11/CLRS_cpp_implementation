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
bool suite_TestActivity_init = false;
#include "test_activity.h"

static TestActivity suite_TestActivity;

static CxxTest::List Tests_TestActivity = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestActivity( "test_activity.h", 4, "TestActivity", suite_TestActivity, Tests_TestActivity );

static class TestDescription_suite_TestActivity_test_textbook : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestActivity_test_textbook() : CxxTest::RealTestDescription( Tests_TestActivity, suiteDescription_TestActivity, 10, "test_textbook" ) {}
 void runTest() { suite_TestActivity.test_textbook(); }
} testDescription_suite_TestActivity_test_textbook;

static class TestDescription_suite_TestActivity_test_empty : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestActivity_test_empty() : CxxTest::RealTestDescription( Tests_TestActivity, suiteDescription_TestActivity, 19, "test_empty" ) {}
 void runTest() { suite_TestActivity.test_empty(); }
} testDescription_suite_TestActivity_test_empty;

static class TestDescription_suite_TestActivity_test_singleton : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestActivity_test_singleton() : CxxTest::RealTestDescription( Tests_TestActivity, suiteDescription_TestActivity, 26, "test_singleton" ) {}
 void runTest() { suite_TestActivity.test_singleton(); }
} testDescription_suite_TestActivity_test_singleton;

static class TestDescription_suite_TestActivity_test_no_conflicts : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestActivity_test_no_conflicts() : CxxTest::RealTestDescription( Tests_TestActivity, suiteDescription_TestActivity, 34, "test_no_conflicts" ) {}
 void runTest() { suite_TestActivity.test_no_conflicts(); }
} testDescription_suite_TestActivity_test_no_conflicts;

static class TestDescription_suite_TestActivity_test_long_act : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestActivity_test_long_act() : CxxTest::RealTestDescription( Tests_TestActivity, suiteDescription_TestActivity, 42, "test_long_act" ) {}
 void runTest() { suite_TestActivity.test_long_act(); }
} testDescription_suite_TestActivity_test_long_act;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
