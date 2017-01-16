// Undirected graph

#pragma once

#include "graph.h"

template<typename N, typename E>
class UnGraph : public Graph<N, E> {
public: 
    UnGraph() : Graph<N,E>() {}
    virtual bool addEdge(int uid, int vid, const E& e);
    virtual bool removeNode(int id);
    virtual bool removeEdge(int uid, int vid);
};

template<typename N, typename E>
bool UnGraph<N,E>::addEdge(int uid, int vid, const E& e) {
    assert(this->V.find(uid) != this->V.end());
    assert(this->V.find(vid) != this->V.end());
    if (this->V[uid]->adj.find(vid) != this->V[uid]->adj.end()) return false;
    this->V[uid]->adj[vid] = e;
    this->V[vid]->adj[uid] = e;
    this->numEdges++;
    return true;
}
template<typename N, typename E>
bool UnGraph<N,E>::removeNode(int id) {
    if (this->V.find(id) == this->V.end()) return false;
    for (auto& e: this->V[id]->adj) this->V[e.first]->adj.erase(id);
    this->numEdges -= this->V[id]->adj.size();
    delete this->V[id];
    this->V.erase(id);
    return true;
}

template<typename N, typename E>
bool UnGraph<N,E>::removeEdge(int uid, int vid) {
    if (this->V.find(uid) == this->V.end() || this->V[uid]->adj.erase(vid) == 0) return false;
    this->V[vid]->adj.erase(uid);
    this->numEdges--;
    return true;
}
