#pragma once
#include "ugraph.h"
#include "dgraph.h"
#include <cxxtest/TestSuite.h>

class TestGraph: public CxxTest::TestSuite {
private:
    UnGraph<int, int> Gu;
    DiGraph<int, int> Gd;
public:
    void tearDown() {
        Gu.clear();
        Gd.clear();
    }

    void test_add_remove_node() {
        TS_ASSERT(Gu.addNode(0, 1));
        TS_ASSERT(!Gu.addNode(0, 1));
        TS_ASSERT_EQUALS(Gu.getNumNodes(), 1);
        Gu.addNode(1, 2);
        Gu.addNode(2, 3);
        Gu.addNode(4, 4);
        TS_ASSERT(Gu[0]);
        TS_ASSERT(!Gu[3]);
        TS_ASSERT_EQUALS(Gu.getNumNodes(), 4);
        TS_ASSERT_EQUALS(Gu[2]->data, 3);
        TS_ASSERT_EQUALS(Gu[4]->data, 4);
        TS_ASSERT(Gu.removeNode(0));
        TS_ASSERT(!Gu.removeNode(0));
        TS_ASSERT_EQUALS(Gu.getNumNodes(), 3);
        TS_ASSERT(!Gu.removeNode(5));   // remove not existing nodes
        TS_ASSERT_EQUALS(Gu.getNumNodes(), 3);
    }

    /**
     *  1  -->   2
     *     \     |
     *      \    |
     *      \|  \/
     *  4 ---   3
     *  (1,2,3) *  (2,3,5) *  (1,3,4) *  (3,4,7) *  (4,3,0)
     * */
    void test_add_remove_edges_direct() {
        Gd.addNode(1, 1);
        Gd.addNode(2, 2);
        Gd.addNode(3, 3);
        Gd.addNode(4, 4);
        TS_ASSERT(Gd.addEdge(1, 2, 3));
        TS_ASSERT(Gd.addEdge(2, 3, 5));
        TS_ASSERT(Gd.addEdge(1, 3, 4));
        TS_ASSERT(Gd.addEdge(3, 4, 7));
        TS_ASSERT(Gd.addEdge(4, 3, 0));
        TS_ASSERT(!Gd.addEdge(1, 3, 8));
        TS_ASSERT_EQUALS(Gd[1]->adj.size(), 2);
        TS_ASSERT_EQUALS(Gd[1]->adj[2], 3);
        TS_ASSERT_EQUALS(Gd[1]->adj[3], 4);
        TS_ASSERT_EQUALS(Gd[2]->adj.size(), 1);
        TS_ASSERT_EQUALS(Gd[2]->adj[3], 5);
        TS_ASSERT_EQUALS(Gd[3]->adj.size(), 1);
        TS_ASSERT_EQUALS(Gd[3]->adj[4], 7);
        TS_ASSERT_EQUALS(Gd[4]->adj.size(), 1);
        TS_ASSERT_EQUALS(Gd[4]->adj[3], 0);
        TS_ASSERT_EQUALS(Gd.getNumEdges(), 5);
        TS_ASSERT(Gd.removeEdge(1, 2));
        TS_ASSERT(!Gd.removeEdge(1, 2));
        TS_ASSERT(!Gd.removeEdge(2, 1));
        TS_ASSERT_EQUALS(Gd.getNumEdges(), 4);
        TS_ASSERT(Gd.removeNode(4));
        TS_ASSERT_EQUALS(Gd.getNumEdges(), 2);
    }

    /**
     * 0  ---  1  -------
     *    \    |         \
     *     \   |          \
     *      \  |           \
     *         2  --  3  -- 4
     * */
    void test_add_remove_edges_undirect() {
        for (int i = 0; i < 5; i++) Gu.addNode(i, i);
        TS_ASSERT(Gu.addEdge(0, 1, 1));
        TS_ASSERT(Gu.addEdge(1, 2, 3));
        TS_ASSERT(Gu.addEdge(0, 2, 2));
        TS_ASSERT(Gu.addEdge(2, 3, 5));
        TS_ASSERT(Gu.addEdge(3, 4, 7));
        TS_ASSERT(Gu.addEdge(1, 4, 4));
        TS_ASSERT(!Gu.addEdge(1, 0, 4));
        TS_ASSERT_EQUALS(Gu.getNumEdges(), 6);
        TS_ASSERT_EQUALS(Gu[1]->adj.size(), 3);
        TS_ASSERT_EQUALS(Gu[1]->adj[0], 1);
        TS_ASSERT_EQUALS(Gu[0]->adj[1], 1);
        TS_ASSERT(!Gu.removeEdge(4, 6));
        TS_ASSERT(Gu.removeEdge(3, 4));
        TS_ASSERT_EQUALS(Gu.getNumEdges(), 5);
        TS_ASSERT(Gu.removeNode(1));
        TS_ASSERT_EQUALS(Gu.getNumEdges(), 2);
        TS_ASSERT_EQUALS(Gu[2]->adj.size(), 2);
    }

    /** textbook
     * 0 -- 1   2 -- 3
     * |    |  /|  / |
     * |    | / | /  |
     * 4    5 --6 -- 7
     * */
    void test_bfs_undirect() {
        NilVisitor<int> visitor;
        for (int i = 0; i < 8; i++) Gu.addNode(i, i);
        Gu.addEdge(0, 1, 0);
        Gu.addEdge(0, 4, 0);
        Gu.addEdge(1, 5, 0);
        Gu.addEdge(2, 5, 0);
        Gu.addEdge(2, 6, 0);
        Gu.addEdge(5, 6, 0);
        Gu.addEdge(2, 3, 0);
        Gu.addEdge(3, 6, 0);
        Gu.addEdge(3, 7, 0);
        Gu.addEdge(6, 7, 0);
        Gu.BFS(1, visitor);
        TS_ASSERT_EQUALS(Gu[0]->parent, 1);
        TS_ASSERT_EQUALS(Gu[0]->distance, 1);
        TS_ASSERT_EQUALS(Gu[1]->parent, -1);       
        TS_ASSERT_EQUALS(Gu[1]->distance, 0);       
        TS_ASSERT_EQUALS(Gu[1]->parent, -1);       
        TS_ASSERT_EQUALS(Gu[2]->distance, 2);       
        TS_ASSERT_EQUALS(Gu[2]->parent, 5);       
        TS_ASSERT(Gu[3]->parent == 2 || Gu[3]->parent == 6);      
        TS_ASSERT_EQUALS(Gu[3]->distance, 3);       
        TS_ASSERT_EQUALS(Gu[4]->parent, 0);       
        TS_ASSERT_EQUALS(Gu[4]->distance, 2);       
        TS_ASSERT_EQUALS(Gu[5]->parent, 1);       
        TS_ASSERT_EQUALS(Gu[5]->distance, 1);       
        TS_ASSERT_EQUALS(Gu[6]->parent, 5);       
        TS_ASSERT_EQUALS(Gu[6]->distance, 2);       
        TS_ASSERT_EQUALS(Gu[7]->parent, 6);       
        TS_ASSERT_EQUALS(Gu[7]->distance, 3);       
    }

    void test_shortest_path_undirect() {
        for (int i = 0; i < 8; i++) Gu.addNode(i, i);
        Gu.addEdge(0, 1, 0);
        Gu.addEdge(0, 4, 0);
        Gu.addEdge(1, 5, 0);
        Gu.addEdge(2, 5, 0);
        Gu.addEdge(2, 6, 0);
        Gu.addEdge(5, 6, 0);
        Gu.addEdge(2, 3, 0);
        Gu.addEdge(3, 6, 0);
        Gu.addEdge(3, 7, 0);
        Gu.addEdge(6, 7, 0);
        std::vector<int> path = Gu.shortestPath(1, 7), answer = {1, 5, 6, 7};
        TS_ASSERT_EQUALS(path, answer);
    }

    /**
     * 0 --> 1     2
     * |  /| |   / |
     * |  /  |  /  |
     * \//  \/ |/ \/
     * 3 <-- 4     5<-
     *             |-|
     *
     * (0 ->) 1 -> 4 -> 3
     * (0 ->) 3 -> 1 -> 4
     * (2 ->) 4 -> 3 -> 1
     * */
    void test_dfs_direct() {
        NilVisitor<int> vst;
        for (int i = 0; i < 6; i++) Gd.addNode(i, i);
        Gd.addEdge(0, 1, 0);
        Gd.addEdge(0, 3, 0); 
        Gd.addEdge(1, 4, 0);
        Gd.addEdge(2, 4, 0);
        Gd.addEdge(2, 5, 0);
        Gd.addEdge(3, 1, 0);
        Gd.addEdge(4, 3, 0);
        Gd.addEdge(5, 5, 0);
        Gd.DFS(vst); 
        TS_ASSERT_EQUALS(Gd[0]->parent, -1);
        bool case1 = (Gd[1]->parent == 0 || Gd[1]->parent == -1) && (Gd[4]->parent == 1) && (Gd[3]->parent == 4);
        bool case2 = (Gd[3]->parent == 0 || Gd[3]->parent == -1) && (Gd[1]->parent == 3) && (Gd[4]->parent == 1);
        bool case3 = (Gd[4]->parent == 2 || Gd[4]->parent == -1) && (Gd[3]->parent == 4) && (Gd[1]->parent == 3);
        TS_ASSERT(case1 || case2 || case3);
        TS_ASSERT_EQUALS(Gd[2]->parent, -1);
        TS_ASSERT(Gd[5]->parent == 2 || Gd[5]->parent == -1);
    }

    /**
     *  0 ---|        1
     *  |    |        |
     *  |    |        |
     *  \/   |       \/
     *  2    ------>  3          8
     *  |
     *  |
     *  \/
     *  4 <----  5
     *  |        |
     *  |        \/
     *  |        6
     *  |        |
     *  |        \/
     *  ------>  7
     * */
    void test_topo_sort_direct() {
        for (int i = 0; i < 9; i++) Gd.addNode(i, i);
        Gd.addEdge(0, 2, 0);
        Gd.addEdge(0, 3, 0);
        Gd.addEdge(1, 3, 0);
        Gd.addEdge(2, 4, 0);
        Gd.addEdge(5, 4, 0);
        Gd.addEdge(5, 6, 0);
        Gd.addEdge(6, 7, 0);
        Gd.addEdge(4, 7, 0);
        std::vector<int> perm = Gd.topologicalSort();
        std::unordered_map<int, int> indexes;
        for (int i = 0; i < 9; i++) indexes.emplace(perm[i], i);
        TS_ASSERT(indexes[3] > indexes[0]);
        TS_ASSERT(indexes[2] > indexes[0]);
        TS_ASSERT(indexes[3] > indexes[1]);
        TS_ASSERT(indexes[4] > indexes[5]);
        TS_ASSERT(indexes[6] > indexes[5]);
        TS_ASSERT(indexes[7] > indexes[6]);
        TS_ASSERT(indexes[7] > indexes[4]);
    }

    /**
     * 0 --> 1 --> 2 -- 3
     * /\  / |     |    |
     * |  /  |     |    |
     * ||/  \/    \/    \/
     * 4 --> 5 --- 6 -> 7(self loop)
     *
     * */
    void test_scc() {
        for (int i = 0; i < 8; i++) Gd.addNode(i, i);
        Gd.addEdge(0, 1, 0);
        Gd.addEdge(1, 4, 0);
        Gd.addEdge(1, 5, 0);
        Gd.addEdge(4, 0, 0);
        Gd.addEdge(1, 2, 0);
        Gd.addEdge(2, 3, 0);
        Gd.addEdge(3, 2, 0);
        Gd.addEdge(2, 6, 0);
        Gd.addEdge(4, 5, 0);
        Gd.addEdge(5, 6, 0);
        Gd.addEdge(6, 5, 0);
        Gd.addEdge(6, 7, 0);
        Gd.addEdge(7, 7, 0);
        std::vector<std::vector<int>> scc = Gd.stronglyConnectedComponents();
        for (auto& cc: scc) {
            std::sort(cc.begin(), cc.end());
            if (cc[0] == 0) {
                TS_ASSERT_EQUALS(cc.size(), 3);
                TS_ASSERT_EQUALS(cc[1], 1);
                TS_ASSERT_EQUALS(cc[2], 4);
            } else if (cc[0] == 2) {
                TS_ASSERT_EQUALS(cc.size(), 2);
                TS_ASSERT_EQUALS(cc[1], 3);
            } else if (cc[0] == 5) {
                TS_ASSERT_EQUALS(cc.size(), 2);
                TS_ASSERT_EQUALS(cc[1], 6);
            } else {
                TS_ASSERT_EQUALS(cc[0], 7);
                TS_ASSERT_EQUALS(cc.size(), 1);
            }
        }
    }
};
