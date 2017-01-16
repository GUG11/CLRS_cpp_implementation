#pragma once
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <cassert>
#include <queue>
#include "../trees/visitor.h"

enum Status {UNDISCOVERED, DISCOVERED, VISITED};

template <typename N, typename E>
struct Vertex {
    N data;
    std::unordered_map<int, E> adj;
    int parent, distance;   // Parent in graph traversal, distance from the source
    Status status;
    Vertex(const N& d) : data(d), parent(-1), distance(-1) {}
};

template <typename N, typename E>
class Graph {
protected:
    std::unordered_map<int, Vertex<N,E>*> V;    // int store the id of a vertex
    bool topoSortOn;
    size_t numEdges;
    std::vector<int> permVertexes;
    void DFS(int id, Visitor<N>& visitor);
public: 
    Graph(): topoSortOn(false), numEdges(0) {}
    virtual ~Graph() {clear();}
    Vertex<N,E>* operator [] (int id) {return V.find(id) == V.end() ? NULL : V[id];}
    size_t getNumNodes() {return V.size();}
    size_t getNumEdges() {return numEdges;}
    bool addNode(int id, const N& data);
    virtual bool addEdge(int uid, int vid, const E& e) = 0;
    virtual bool removeNode(int id) = 0;
    virtual bool removeEdge(int uid, int vid) = 0;
    void BFS(int id, Visitor<N>& visitor);
    std::vector<int> shortestPath(int src, int dst);
    void DFS(Visitor<N>& visitor);
    std::vector<int> topologicalSort();
    void clear();
};

template <typename N, typename E>
void Graph<N,E>::clear() {
    for (auto& e: V) delete e.second;
    V.clear();
    numEdges = 0;
}

template <typename N, typename E>
bool Graph<N,E>::addNode(int id, const N& data) {
    if (V.find(id) != V.end()) return false;
    V[id] = new Vertex<N,E>(data);
    return true;
}

template <typename N, typename E>
void Graph<N,E>::BFS(int id, Visitor<N>& visitor) {
    // initialization
    for (auto v: V) {
        v.second->parent = -1;
        v.second->distance = v.first == id ? 0 : -1;
        v.second->status = UNDISCOVERED;
    } 
    std::queue<int> Q;
    // bfs
    if (V.find(id) != V.end()) {
        V[id]->parent = -1;
        V[id]->distance = 0;
        Q.push(id);
        while (!Q.empty()) {
            id = Q.front(); Q.pop();
            visitor(V[id]->data);
            for (auto nb: V[id]->adj) {
                if (V[nb.first]->status == UNDISCOVERED) {
                    V[nb.first]->status = DISCOVERED;
                    V[nb.first]->parent = id;
                    V[nb.first]->distance = V[id]->distance + 1;
                    Q.push(nb.first);
                }
            }
            V[id]->status = VISITED;
        }
    }
}

template <typename N, typename E>
std::vector<int> Graph<N,E>::shortestPath(int src, int dst) {
    assert(V.find(src) != V.end());
    assert(V.find(dst) != V.end());
    std::vector<int> path;
    NilVisitor<N> visitor;
    BFS(src, visitor);
    while (dst != src && dst != -1) {
        path.push_back(dst);
        dst = V[dst]->parent;
    }
    if (dst == src) path.push_back(src);
    else path.clear();  // no path exists
    std::reverse(path.begin(), path.end());
    return path;
}

template <typename N, typename E>
void Graph<N,E>::DFS(Visitor<N>& visitor) {
    // initialization
    for (auto& u : V) {
        u.second->status = UNDISCOVERED;
        u.second->parent = -1;
    }
    for (auto& u : V) {
        if (u.second->status == UNDISCOVERED) DFS(u.first, visitor);
    }
}

template <typename N, typename E>
void Graph<N,E>::DFS(int id, Visitor<N>& visitor) {
    V[id]->status = DISCOVERED;
    for (auto& v : V[id]->adj) {
        if (V[v.first]->status == UNDISCOVERED) {
            V[v.first]->parent = id;
            DFS(v.first, visitor);
        }
    }
    visitor(V[id]->data);
    if (topoSortOn) permVertexes.push_back(id);
    V[id]->status = VISITED;
}

template <typename N, typename E>
std::vector<int> Graph<N,E>::topologicalSort() {
    topoSortOn = true;
    NilVisitor<N> visitor;
    permVertexes.clear();
    DFS(visitor);
    std::reverse(permVertexes.begin(), permVertexes.end());
    topoSortOn = false;
    return permVertexes;
}
