// Direct Graph

#pragma once

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
    std::vector<std::vector<int>> stronglyConnectedComponents(); // todo
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
    std::vector<std::vector<int>> SCC;
    BufferVisitor<N> vst;
    Graph<N,E>::DFS(vst);
    DiGraph<N,E> GT = transpose();
    std::vector<int> nids = GT.getNodeIds();
    std::sort(nids.begin(), nids.end(), [&GT](const int i, const int j) {return GT[i]->ftime > GT[j]->ftime;});
    GT.searchInit(-1);
    for (int u : nids) {
        vst.buf.clear();
        if (GT[u]->status == UNDISCOVERED) GT.DFS(u, vst);
        SCC.push_back(vst.buf);
    }
    return SCC;
}
