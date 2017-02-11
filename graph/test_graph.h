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

    /**
     *      1 --(8)-- 2 --(7)-- 4
     *    / |       /   \       | \
     *  (4) |     (2)    \      | (9)
     *  /   |     /       \     |   \
     * 0   (11)  3        (4) (14)   5
     *  \   |   / \         \   |   /
     *  (8) | (7) (6)        \  | (10)
     *    \ | /     \         \ | /
     *      8 --(1)-- 7 --(2)-- 6
     * */
    void test_mst_prim() {
        std::vector<Edge<int>> mstEdges;
        for (int i = 0; i < 9; i++) { Gu.addNode(i, i); }
        Gu.addEdge(0, 1, 4);
        Gu.addEdge(1, 2, 8);
        Gu.addEdge(2, 4, 7);
        Gu.addEdge(2, 3, 2);
        Gu.addEdge(1, 8, 11);
        Gu.addEdge(0, 8, 8);
        Gu.addEdge(2, 6, 4);
        Gu.addEdge(3, 8, 7);
        Gu.addEdge(3, 7, 6);
        Gu.addEdge(4, 5, 9);
        Gu.addEdge(4, 6, 14);
        Gu.addEdge(5, 6, 10);
        Gu.addEdge(6, 7, 2);
        Gu.addEdge(7, 8, 1);
        mstEdges = Gu.MSTPrim();
        // check the tree
        UnGraph<int, int> mstTree;
        for (int i = 0; i < 9; i++) { Gu.addNode(i, i); }
        for (auto& e: mstEdges) mstTree.addEdge(e);
        TS_ASSERT_EQUALS(mstTree[0]->adj.size(), 1);
        TS_ASSERT_DIFFERS(mstTree[0]->adj.find(1), mstTree[0]->adj.end());
        TS_ASSERT_EQUALS(mstTree[1]->adj.size(), 2);
        TS_ASSERT_DIFFERS(mstTree[1]->adj.find(2), mstTree[1]->adj.end());
        TS_ASSERT_EQUALS(mstTree[2]->adj.size(), 4);
        TS_ASSERT_DIFFERS(mstTree[2]->adj.find(3), mstTree[2]->adj.end());
        TS_ASSERT_DIFFERS(mstTree[2]->adj.find(4), mstTree[2]->adj.end());
        TS_ASSERT_DIFFERS(mstTree[2]->adj.find(6), mstTree[2]->adj.end());
        TS_ASSERT_EQUALS(mstTree[4]->adj.size(), 2);
        TS_ASSERT_DIFFERS(mstTree[4]->adj.find(5), mstTree[4]->adj.end());
        TS_ASSERT_EQUALS(mstTree[6]->adj.size(), 2);
        TS_ASSERT_DIFFERS(mstTree[6]->adj.find(7), mstTree[6]->adj.end());
        TS_ASSERT_EQUALS(mstTree[7]->adj.size(), 2);
        TS_ASSERT_DIFFERS(mstTree[7]->adj.find(8), mstTree[7]->adj.end());
    }

    void test_mst_kruskal() {
        std::vector<Edge<int>> mstEdges;
        for (int i = 0; i < 9; i++) { Gu.addNode(i, i); }
        Gu.addEdge(0, 1, 4);
        Gu.addEdge(1, 2, 8);
        Gu.addEdge(2, 4, 7);
        Gu.addEdge(2, 3, 2);
        Gu.addEdge(1, 8, 11);
        Gu.addEdge(0, 8, 8);
        Gu.addEdge(2, 6, 4);
        Gu.addEdge(3, 8, 7);
        Gu.addEdge(3, 7, 6);
        Gu.addEdge(4, 5, 9);
        Gu.addEdge(4, 6, 14);
        Gu.addEdge(5, 6, 10);
        Gu.addEdge(6, 7, 2);
        Gu.addEdge(7, 8, 1);
        mstEdges = Gu.MSTKruskal();
        // check the tree
        UnGraph<int, int> mstTree;
        for (int i = 0; i < 9; i++) { Gu.addNode(i, i); }
        for (auto& e: mstEdges) mstTree.addEdge(e);
        TS_ASSERT_EQUALS(mstTree[0]->adj.size(), 1);
        TS_ASSERT_DIFFERS(mstTree[0]->adj.find(1), mstTree[0]->adj.end());
        TS_ASSERT_EQUALS(mstTree[1]->adj.size(), 2);
        TS_ASSERT_DIFFERS(mstTree[1]->adj.find(2), mstTree[1]->adj.end());
        TS_ASSERT_EQUALS(mstTree[2]->adj.size(), 4);
        TS_ASSERT_DIFFERS(mstTree[2]->adj.find(3), mstTree[2]->adj.end());
        TS_ASSERT_DIFFERS(mstTree[2]->adj.find(4), mstTree[2]->adj.end());
        TS_ASSERT_DIFFERS(mstTree[2]->adj.find(6), mstTree[2]->adj.end());
        TS_ASSERT_EQUALS(mstTree[4]->adj.size(), 2);
        TS_ASSERT_DIFFERS(mstTree[4]->adj.find(5), mstTree[4]->adj.end());
        TS_ASSERT_EQUALS(mstTree[6]->adj.size(), 2);
        TS_ASSERT_DIFFERS(mstTree[6]->adj.find(7), mstTree[6]->adj.end());
        TS_ASSERT_EQUALS(mstTree[7]->adj.size(), 2);
        TS_ASSERT_DIFFERS(mstTree[7]->adj.find(8), mstTree[7]->adj.end());
    }

    /** case : CLRS Figure 24.4 (p652)
     * 0:'s', 1:'t', 2:'y', 3:'x', 4:'z' 
     * */
    void test_bellman_ford() {
        for (int i = 0; i < 5; i++) Gd.addNode(i, i);
        Gd.addEdge(0, 1, 6);
        Gd.addEdge(0, 2, 7);
        Gd.addEdge(1, 4, -4);
        Gd.addEdge(1, 2, 8);
        Gd.addEdge(1, 3, 5);
        Gd.addEdge(2, 3, -3);
        Gd.addEdge(2, 4, 9);
        Gd.addEdge(3, 1, -2);
        Gd.addEdge(4, 0, 2);
        Gd.addEdge(4, 3, 7);
        bool res = Gd.bellmanFord(0);   
        TS_ASSERT(res);
        TS_ASSERT_EQUALS(Gd[0]->parent, -1);
        TS_ASSERT_EQUALS(Gd[0]->weightedDistance, 0);
        TS_ASSERT_EQUALS(Gd[1]->parent, 3);
        TS_ASSERT_EQUALS(Gd[1]->weightedDistance, 2);
        TS_ASSERT_EQUALS(Gd[2]->parent, 0);
        TS_ASSERT_EQUALS(Gd[2]->weightedDistance, 7);
        TS_ASSERT_EQUALS(Gd[3]->parent, 2);
        TS_ASSERT_EQUALS(Gd[3]->weightedDistance, 4);
        TS_ASSERT_EQUALS(Gd[4]->parent, 1);
        TS_ASSERT_EQUALS(Gd[4]->weightedDistance, -2);
    }

    /**
     * CLRS Figure 24.5 (p656)
     *  0 -(1)-> 1 --(4)-> 2 --(5)-> 3
     *            \       /
     *         (-2)<--4<--(-4)
     * */
    void test_bellman_ford_neg_cycle() {
        for (int i = 0; i < 5; i++) Gd.addNode(i, i);
        Gd.addEdge(0, 1, 1);
        Gd.addEdge(1, 2, 4);
        Gd.addEdge(2, 3, 5);
        Gd.addEdge(2, 4, -4);
        Gd.addEdge(4, 1, -2);
        bool res = Gd.bellmanFord(0);
        TS_ASSERT(!res);
    }

    /**
     * 0:'r', 1:'s', 2:'t', 3:'x', 4:'y', 5:'z'
     * */
    void test_dag_topsort_shortest_path() {
        for (int i = 0; i < 6; i++) Gd.addNode(i, i);
        Gd.addEdge(0, 1, 5);
        Gd.addEdge(0, 2, 3);
        Gd.addEdge(1, 2, 2);
        Gd.addEdge(1, 3, 6);
        Gd.addEdge(2, 3, 7);
        Gd.addEdge(2, 4, 4);
        Gd.addEdge(2, 5, 2);
        Gd.addEdge(3, 4, -1);
        Gd.addEdge(3, 5, 1);
        Gd.addEdge(4, 5, -2);
        Gd.dagShortestPaths(1);       
        TS_ASSERT_EQUALS(Gd[0]->status, UNDISCOVERED);
        TS_ASSERT_EQUALS(Gd[1]->parent, -1);
        TS_ASSERT_EQUALS(Gd[1]->weightedDistance, 0);
        TS_ASSERT_EQUALS(Gd[2]->parent, 1);
        TS_ASSERT_EQUALS(Gd[2]->weightedDistance, 2);
        TS_ASSERT_EQUALS(Gd[3]->parent, 1);
        TS_ASSERT_EQUALS(Gd[3]->weightedDistance, 6);
        TS_ASSERT_EQUALS(Gd[4]->parent, 3);
        TS_ASSERT_EQUALS(Gd[4]->weightedDistance, 5);
        TS_ASSERT_EQUALS(Gd[5]->parent, 4);
        TS_ASSERT_EQUALS(Gd[5]->weightedDistance, 3);
    }

    /**
     * Figure 24.6 (p659)
     * 0:'s', 1:'t', 2:'x', 3:'y', 4:'z'
     * */
    void test_dijkstra() {
        for (int i = 0; i < 5; i++) Gd.addNode(i, i);
        Gd.addEdge(0, 1, 10);
        Gd.addEdge(0, 3, 5);
        Gd.addEdge(1, 2, 1);
        Gd.addEdge(1, 3, 2);
        Gd.addEdge(2, 4, 4);
        Gd.addEdge(3, 1, 3);
        Gd.addEdge(3, 2, 9);
        Gd.addEdge(3, 4, 2);
        Gd.addEdge(4, 0, 7);
        Gd.addEdge(4, 2, 6);
        Gd.dijkstra(0);
        TS_ASSERT_EQUALS(Gd[0]->parent, -1);
        TS_ASSERT_EQUALS(Gd[0]->weightedDistance, 0);
        TS_ASSERT_EQUALS(Gd[1]->parent, 3);
        TS_ASSERT_EQUALS(Gd[1]->weightedDistance, 8);
        TS_ASSERT_EQUALS(Gd[2]->parent, 1);
        TS_ASSERT_EQUALS(Gd[2]->weightedDistance, 9);
        TS_ASSERT_EQUALS(Gd[3]->parent, 0);
        TS_ASSERT_EQUALS(Gd[3]->weightedDistance, 5);
        TS_ASSERT_EQUALS(Gd[4]->parent, 3);
        TS_ASSERT_EQUALS(Gd[4]->weightedDistance, 7);
    }
};
