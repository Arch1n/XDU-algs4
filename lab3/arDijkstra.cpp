//
// Created by arch0n on 18-12-9.
//

#include <map>
#include "arDijkstra.h"

arDijkstra::arDijkstra(size_t n):arGraph(n){
    dis.resize(n);
    weight.resize(n);
    H.resize(n);
    last.clear();
#ifdef AR_DRAW
    fa.resize(n);
#endif

}

void arDijkstra::work(int s, int d) {
    pq Q;
    if(last.empty()){
        std::fill(std::begin(H), std::end(H), Q.end());
        std::fill(std::begin(dis), std::end(dis), std::numeric_limits<double>::max());
        std::fill(std::begin(weight), std::end(weight), std::numeric_limits<double>::max());
#ifdef AR_DRAW
        std::fill(std::begin(fa), std::end(fa), -1);
#endif
    }
    else {
        for(auto c:last){
            dis[c] = std::numeric_limits<double>::max();
            weight[c] = std::numeric_limits<double>::max();
            H[c] = Q.end();
#ifdef AR_DRAW
            fa[c] = -1;
#endif
        }
        last.clear();
    }
    dis[s] = 0;
    weight[s] = 0;
    last.push_back(s);
    H[s] = Q.push(std::make_pair(weight[s], s));
    while(!Q.empty()){
        auto u = Q.top().second;
        Q.pop();
        if(u == d)
            break;
        for(const auto& id: G[u]){
            auto& [from, to, val] = edges[id];
#ifdef AR_DRAW
            drawEdge.push_back(id);
#endif
            auto delta = weight[u] + val - get_dis(arMap[d], arMap[u]) + get_dis(arMap[d], arMap[to]);
            if(delta < weight[to] - EPS){
                dis[to] = dis[u] + val;
                weight[to] = delta;
                last.push_back(to);
#ifdef AR_DRAW
                fa[to] = u;
#endif
                //std::cerr << to << " : " <<weight[to] << std::endl;
                auto to_push = std::make_pair(weight[to], to);
                if(H[to] == Q.end())
                    H[to] = Q.push(to_push);
                else
                    Q.modify(H[to], to_push);
                //std::cerr << to << " : " <<weight[to] << std::endl;
            }
        }
    }
    //std::cerr << "from " << s << " to " << d << " dis = " << dis[d] << std::endl;
}