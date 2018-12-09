//
// Created by arch0n on 18-12-9.
//

#include "arDijkstra.h"

arDijkstra::arDijkstra(size_t n):arGraph(n){
    dis.resize(n);
    weight.resize(n);
}

void arDijkstra::work(int s, int d) {
    std::fill(std::begin(dis), std::end(dis), std::numeric_limits<double>::max());
    std::fill(std::begin(weight), std::end(weight), std::numeric_limits<double>::max());
    std::unordered_map<int, pq::point_iterator> H;
    pq Q;
    dis[s] = 0;
    weight[s] = 0;
    H[s] = Q.push(std::make_pair(weight[s], s));
    while(!Q.empty()){
        auto u = Q.top().second;
        Q.pop();
        for(const auto& id: G[u]){
            auto& [from, to, val] = edges[id];
            auto delta = weight[u] + val ;
            if(delta < weight[to]){
                dis[to] = weight[u] + val;
                weight[to] = delta;
                if(H.count(to))
                    Q.modify(H[to], std::make_pair(dis[to], to));
                else
                    H[to] = Q.push(std::make_pair(dis[to], to));
            }
        }
    }
    std::cerr << "from " << s << " to " << d << " dis = " << dis[d] << std::endl;
}