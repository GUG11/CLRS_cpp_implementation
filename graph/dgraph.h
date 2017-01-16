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
    std::vector<std::unordered_set<int>> stronglyConnectedComponents(); // todo
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
