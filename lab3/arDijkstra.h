//
// Created by arch0n on 18-12-9.
//

#ifndef LAB3_ARDIJKSTRA_H
#define LAB3_ARDIJKSTRA_H

#include "arGraph.h"
#include <limits>
#include <unordered_map>
#include <ext/pb_ds/priority_queue.hpp>

class arDijkstra: public arGraph{
public:
    std::vector<double> dis;
    std::vector<double> weight;
    using pqNode = std::pair<double, int>;
    using pq = __gnu_pbds::priority_queue<pqNode, std::greater<pqNode>, __gnu_pbds::pairing_heap_tag>;
    arDijkstra(size_t n);
    void work(int s, int d);
};


#endif //LAB3_ARDIJKSTRA_H
