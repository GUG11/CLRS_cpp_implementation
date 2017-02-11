// Direct Graph

#pragma once

#include <iterator>
#include "graph.h"

template<typename N, typename E>
class DiGraph : public Graph<N, E> {
public: 
    DiGraph() : Graph<N,E>() {}
    virtual bool addEdge(int uid, int vid, const E& e);
    virtual bool removeNode(int id);
    virtual bool removeEdge(int uid, int vid);
    std::vector<int> topologicalSort();
    DiGraph<N, E> transpose();   
    std::vector<std::vector<int>> stronglyConnectedComponents();
    // shortest paths
    bool bellmanFord(int source);   // return true iff no negative-weight cycles reachable
    void dagShortestPaths(int source);  // assume the graph is directed and acyclic
    void dijkstra(int source);  // assume all edge weights are nonnegative
};

template<typename N, typename E>
bool DiGraph<N,E>::addEdge(int uid, int vid, const E& e) {
    assert(this->V.find(uid) != this->V.end());
    assert(this->V.find(vid) != this->V.end());
    if (this->V[uid]->adj.find(vid) != this->V[uid]->adj.end()) return false;
    this->V[uid]->adj[vid] = e;
    this->numEdges++;
    return true;
}

template<typename N, typename E>
bool DiGraph<N,E>::removeNode(int id) {
    if (this->V.find(id) == this->V.end()) return false;
    for (auto& v: this->V) this->numEdges -= v.second->adj.erase(id);  // remove in arcs
    this->numEdges -= this->V[id]->adj.size();  // remove out arcs
    delete this->V[id];
    this->V.erase(id);
    return true;
}

template<typename N, typename E>
bool DiGraph<N,E>::removeEdge(int uid, int vid) {
    bool res = false;
    if (this->V.find(uid) != this->V.end()) {
        res = this->V[uid]->adj.erase(vid) > 0;
        this->numEdges -= int(res);
    }
    return res;
}

template <typename N, typename E>
std::vector<int> DiGraph<N,E>::topologicalSort() {
    BufferVisitor<N> visitor;
    Graph<N,E>::DFS(visitor);
    std::reverse(visitor.buf.begin(), visitor.buf.end());
    return visitor.buf;
}

template<typename N, typename E>
DiGraph<N, E> DiGraph<N,E>::transpose() {
    DiGraph<N, E> GT;
    for (auto& v: this->V) {  // vertexes
        GT.addNode(v.first, v.second->data);
        GT[v.first]->ftime = v.second->ftime;
    }
    for (auto& v: this->V) {  // reverse edges
        for (auto& u: v.second->adj) {
            GT.addEdge(u.first, v.first, u.second);
        }
    }
    return GT;
}
    
template<typename N, typename E>
std::vector<std::vector<int>> DiGraph<N,E>::stronglyConnectedComponents() {
    std::vector<std::vector<int>> scc;
    std::vector<int> tpSeq = topologicalSort();
    BufferVisitor<N> vst;
    DiGraph<N, E> GT = transpose();
    GT.searchInit(-1);
    for (int u : tpSeq) {
        vst.buf.clear();
        if (GT[u]->status == UNDISCOVERED) GT.DFS(u, vst);
        scc.push_back(vst.buf);
    }
    return scc;
}

template <typename N, typename E>
bool DiGraph<N,E>::bellmanFord(int source) {
    bool res = true;
    if (this->V.find(source) == this->V.end()) res = false;
    else {
        Graph<N,E>::initializeSingleSource(source);
        for (int i = 0; i < this->V.size() - 1; i++) {
            // loop each edge
            for (auto& u: this->V) {
                for (auto& v: u.second->adj) {
                    Graph<N,E>::relax(u.first, v.first);
                }
            }
        }
        // check negative loop
        for (auto& u: this->V) {
            for (auto& v: u.second->adj) {
                if (this->V[v.first]->distance > this->V[u.first]->distance + v.second) {
                    res = false;
                    goto endloop;
                }
            }
        }
    }
endloop:
    return res;
}

template <typename N, typename E>
void DiGraph<N,E>::dagShortestPaths(int source) {
    std::vector<int> tpsSeq = topologicalSort();
    Graph<N,E>::initializeSingleSource(source);
    for (int uid : tpsSeq) {
        for (auto& v: this->V[uid]->adj) {
            Graph<N,E>::relax(uid, v.first);
        }
    }
}

template <typename N, typename E>
void DiGraph<N,E>::dijkstra(int source) {
    typename std::map<E, int>::iterator it;
    E currWD;
    int currId;
    Graph<N,E>::initializeSingleSource(source);
    std::map<E, int> PQ;   // min-priority queue
    std::map<int, typename std::map<E, int>::iterator> locs; // track location of id in PQ
    for (auto& v: this->V) {
        it = PQ.emplace(v.second->weightedDistance, v.first).first;
        locs.emplace(v.first, it);
    }
    while (!PQ.empty()) {
        it = PQ.begin();
        currWD = it->first;
        currId = it->second;
        PQ.erase(it);
        locs.erase(currId);
        for (auto& v: this->V[currId]->adj) {
            if (PQ.find(v.first) != PQ.end()) {
                Graph<N,E>::relax(currId, v.first);
                it = locs[v.first];
                // update PQ and locs
                if (it->first != this->V[v.first]->weightedDistance) {
                    PQ.erase(it);
                    it = PQ.emplace(this->V[v.first]->weightedDistance, v.first).first;
                    locs[v.first] = it;
                }
            }
        }
    }
}
