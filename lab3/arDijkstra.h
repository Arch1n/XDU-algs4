//
// Created by arch0n on 18-12-9.
//

#ifndef LAB3_ARDIJKSTRA_H
#define LAB3_ARDIJKSTRA_H

#include "arGraph.h"
#include <limits>
#include <unordered_map>
#include <cassert>
#include <ext/pb_ds/priority_queue.hpp>


double get_dis(const point& A, const point& B);
class arDijkstra: public arGraph{
    const double EPS = 0.000001;
public:
    using pqNode = std::pair<double, int>;
    using pq = __gnu_pbds::priority_queue<pqNode, std::greater<pqNode>, __gnu_pbds::pairing_heap_tag>;
    std::vector<double> dis;
    std::vector<double> weight;
#ifdef AR_DRAW
    std::vector<int> fa;
#endif
    std::vector<pq::point_iterator> H;
    std::list<int> last;
    arDijkstra(size_t n);
    void work(int s, int d);
};


#endif //LAB3_ARDIJKSTRA_H
