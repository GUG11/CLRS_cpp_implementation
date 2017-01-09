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
bool suite_TestHuffman_init = false;
#include "test_huffman.h"

static TestHuffman suite_TestHuffman;

static CxxTest::List Tests_TestHuffman = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestHuffman( "test_huffman.h", 5, "TestHuffman", suite_TestHuffman, Tests_TestHuffman );

static class TestDescription_suite_TestHuffman_test_count1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestHuffman_test_count1() : CxxTest::RealTestDescription( Tests_TestHuffman, suiteDescription_TestHuffman, 7, "test_count1" ) {}
 void runTest() { suite_TestHuffman.test_count1(); }
} testDescription_suite_TestHuffman_test_count1;

static class TestDescription_suite_TestHuffman_test_count2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestHuffman_test_count2() : CxxTest::RealTestDescription( Tests_TestHuffman, suiteDescription_TestHuffman, 20, "test_count2" ) {}
 void runTest() { suite_TestHuffman.test_count2(); }
} testDescription_suite_TestHuffman_test_count2;

static class TestDescription_suite_TestHuffman_test_leaves1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestHuffman_test_leaves1() : CxxTest::RealTestDescription( Tests_TestHuffman, suiteDescription_TestHuffman, 32, "test_leaves1" ) {}
 void runTest() { suite_TestHuffman.test_leaves1(); }
} testDescription_suite_TestHuffman_test_leaves1;

static class TestDescription_suite_TestHuffman_test_leaves2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestHuffman_test_leaves2() : CxxTest::RealTestDescription( Tests_TestHuffman, suiteDescription_TestHuffman, 46, "test_leaves2" ) {}
 void runTest() { suite_TestHuffman.test_leaves2(); }
} testDescription_suite_TestHuffman_test_leaves2;

static class TestDescription_suite_TestHuffman_test_huffman_tree1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestHuffman_test_huffman_tree1() : CxxTest::RealTestDescription( Tests_TestHuffman, suiteDescription_TestHuffman, 70, "test_huffman_tree1" ) {}
 void runTest() { suite_TestHuffman.test_huffman_tree1(); }
} testDescription_suite_TestHuffman_test_huffman_tree1;

static class TestDescription_suite_TestHuffman_test_huffman_tree2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestHuffman_test_huffman_tree2() : CxxTest::RealTestDescription( Tests_TestHuffman, suiteDescription_TestHuffman, 117, "test_huffman_tree2" ) {}
 void runTest() { suite_TestHuffman.test_huffman_tree2(); }
} testDescription_suite_TestHuffman_test_huffman_tree2;

static class TestDescription_suite_TestHuffman_test_encode_table1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestHuffman_test_encode_table1() : CxxTest::RealTestDescription( Tests_TestHuffman, suiteDescription_TestHuffman, 138, "test_encode_table1" ) {}
 void runTest() { suite_TestHuffman.test_encode_table1(); }
} testDescription_suite_TestHuffman_test_encode_table1;

static class TestDescription_suite_TestHuffman_test_encode_table2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestHuffman_test_encode_table2() : CxxTest::RealTestDescription( Tests_TestHuffman, suiteDescription_TestHuffman, 155, "test_encode_table2" ) {}
 void runTest() { suite_TestHuffman.test_encode_table2(); }
} testDescription_suite_TestHuffman_test_encode_table2;

static class TestDescription_suite_TestHuffman_test_encode_decode : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestHuffman_test_encode_decode() : CxxTest::RealTestDescription( Tests_TestHuffman, suiteDescription_TestHuffman, 173, "test_encode_decode" ) {}
 void runTest() { suite_TestHuffman.test_encode_decode(); }
} testDescription_suite_TestHuffman_test_encode_decode;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
