// Undirected graph

#pragma once

#include "graph.h"

template<typename E>
struct EdgeCmp {
    bool operator () (const Edge<E>& a, const Edge<E>& b) {
        return a.data < b.data;
    }
};

template<typename E>
bool edgeCmp(const Edge<E>& a, const Edge<E>& b) {return a.data < b.data;}

template<typename N, typename E>
class UnGraph : public Graph<N, E> {
protected:
    std::vector<Edge<E>> MSTPrim(int id);
public: 
    UnGraph() : Graph<N,E>() {}
    virtual bool addEdge(int uid, int vid, const E& e);
    bool addEdge(const Edge<E>& edge) {return addEdge(edge.uid, edge.vid, edge.data);}
    virtual bool removeNode(int id);
    virtual bool removeEdge(int uid, int vid);
    // MST algorithms
    std::vector<Edge<E>> MSTPrim();
    std::vector<Edge<E>> MSTKruskal();
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

template<typename N, typename E>
std::vector<Edge<E>> UnGraph<N,E>::MSTPrim(int id) {
    std::priority_queue<Edge<E>, std::vector<Edge<E>>, EdgeCmp<E>> candidates;
    Graph<N,E>::searchInit(id);
    Edge<E> edge(-1, id, 0); 
    std::vector<Edge<E>> mstEdges;
    candidates.push(edge);
    this->V[id]->status = DISCOVERED;
    while (!candidates.empty()) {
        edge = candidates.top();
        candidates.pop();
        id = edge.vid;
        if (this->V[id]->status == VISITED) continue;
        this->V[id]->parent = edge.uid;   // connect current id to its parent
        mstEdges.push_back(edge);
        for (auto& u : this->V[id]->adj) {
            if (this->V[u.first]->status != VISITED) {
                candidates.push(Edge<E>(id, u.first, u.second));
                this->V[u.first]->status = DISCOVERED;
            }
        }
        this->V[id]->status = VISITED;
    }
    return mstEdges;
}

template<typename N, typename E>
std::vector<Edge<E>> UnGraph<N,E>::MSTPrim() {
    return MSTPrim(this->V.begin()->first);
}

template<typename N, typename E>
std::vector<Edge<E>> UnGraph<N,E>::MSTKruskal() {
    std::vector<Edge<E>> mstEdges, allEdges;
    std::unordered_map<int, int> setMap;
    std::unordered_map<int, int> mapSize;
    int mapId = -1;
    for (auto& v: this->V) { 
        setMap.emplace(v.first, v.first); 
        mapSize.emplace(v.first, 1);
        for (auto& u: v.second->adj) {
            if (v.first < u.first) allEdges.push_back(Edge<E>(v.first, u.first, u.second));
        }
    }
    std::sort(allEdges.begin(), allEdges.end(), edgeCmp<E>);
    for (auto& e: allEdges) {
        if (setMap[e.uid] != setMap[e.vid]) {
            mstEdges.push_back(e);
            // Union
            if (mapSize[e.uid] < mapSize[e.vid]) {
                mapId = mapSize[e.uid];
                mapSize[e.vid] += mapSize[e.uid];
                mapSize.erase(mapId);
                for (auto& m: setMap) {
                    if (m.second == mapId) m.second = mapSize[e.vid];
                }
            } else {
                mapId = mapSize[e.vid];
                mapSize[e.uid] += mapSize[e.vid];
                mapSize.erase(mapId);
                for (auto& m: setMap) {
                    if (m.second == mapId) m.second = mapSize[e.uid];
                }
            }
        }
    }
    return mstEdges;
}
