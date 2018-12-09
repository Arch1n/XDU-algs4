//
// Created by arch0n on 18-12-9.
//

#include "arGraph.h"

arGraph::arGraph(size_t n) {
    edges.clear();
    G.clear();
    G.resize(n);
}

void arGraph::addEdge(const arGraph::node &t) {
    auto from = std::get<0>(t);
    G[from].push_back(edges.size());
    edges.push_back(t);
}

void arGraph::addEdge(int from, int to, double val) {
    G[from].push_back(edges.size());
    edges.emplace_back(from, to, val);
}