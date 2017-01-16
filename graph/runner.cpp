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
bool suite_TestGraph_init = false;
#include "test_graph.h"

static TestGraph suite_TestGraph;

static CxxTest::List Tests_TestGraph = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestGraph( "test_graph.h", 6, "TestGraph", suite_TestGraph, Tests_TestGraph );

static class TestDescription_suite_TestGraph_test_add_remove_node : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestGraph_test_add_remove_node() : CxxTest::RealTestDescription( Tests_TestGraph, suiteDescription_TestGraph, 16, "test_add_remove_node" ) {}
 void runTest() { suite_TestGraph.test_add_remove_node(); }
} testDescription_suite_TestGraph_test_add_remove_node;

static class TestDescription_suite_TestGraph_test_add_remove_edges_direct : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestGraph_test_add_remove_edges_direct() : CxxTest::RealTestDescription( Tests_TestGraph, suiteDescription_TestGraph, 43, "test_add_remove_edges_direct" ) {}
 void runTest() { suite_TestGraph.test_add_remove_edges_direct(); }
} testDescription_suite_TestGraph_test_add_remove_edges_direct;

static class TestDescription_suite_TestGraph_test_add_remove_edges_undirect : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestGraph_test_add_remove_edges_undirect() : CxxTest::RealTestDescription( Tests_TestGraph, suiteDescription_TestGraph, 79, "test_add_remove_edges_undirect" ) {}
 void runTest() { suite_TestGraph.test_add_remove_edges_undirect(); }
} testDescription_suite_TestGraph_test_add_remove_edges_undirect;

static class TestDescription_suite_TestGraph_test_bfs_undirect : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestGraph_test_bfs_undirect() : CxxTest::RealTestDescription( Tests_TestGraph, suiteDescription_TestGraph, 106, "test_bfs_undirect" ) {}
 void runTest() { suite_TestGraph.test_bfs_undirect(); }
} testDescription_suite_TestGraph_test_bfs_undirect;

static class TestDescription_suite_TestGraph_test_shortest_path_undirect : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestGraph_test_shortest_path_undirect() : CxxTest::RealTestDescription( Tests_TestGraph, suiteDescription_TestGraph, 139, "test_shortest_path_undirect" ) {}
 void runTest() { suite_TestGraph.test_shortest_path_undirect(); }
} testDescription_suite_TestGraph_test_shortest_path_undirect;

static class TestDescription_suite_TestGraph_test_dfs_direct : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestGraph_test_dfs_direct() : CxxTest::RealTestDescription( Tests_TestGraph, suiteDescription_TestGraph, 167, "test_dfs_direct" ) {}
 void runTest() { suite_TestGraph.test_dfs_direct(); }
} testDescription_suite_TestGraph_test_dfs_direct;

static class TestDescription_suite_TestGraph_test_topo_sort_direct : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestGraph_test_topo_sort_direct() : CxxTest::RealTestDescription( Tests_TestGraph, suiteDescription_TestGraph, 205, "test_topo_sort_direct" ) {}
 void runTest() { suite_TestGraph.test_topo_sort_direct(); }
} testDescription_suite_TestGraph_test_topo_sort_direct;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
