//
// Created by arch0n on 18-12-9.
//

#ifndef LAB3_ARGRAPH_H
#define LAB3_ARGRAPH_H

#include <list>
#include <iostream>
#include <utility>
#include <vector>
#include <tuple>
#include <cmath>

using point = std::pair<int, int>;
extern std::vector<point > arMap;

class arGraph {
protected:
    using node = std::tuple<int, int, double>;
    std::vector<std::list<size_t>> G;
    std::vector<node> edges;
public:
    arGraph() = default;
    arGraph(size_t n);
    void addEdge(const node&);
    void addEdge(int, int, double);
};



#endif //LAB3_ARGRAPH_H
