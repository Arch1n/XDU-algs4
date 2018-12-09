#include "arDijkstra.h"
#include <fstream>

void readData();
std::vector<point> arMap;

int main(int argc, char** argv) {

    //
    return 0;
}

double get_dis(const point& A, const point& B){
    auto [ax, ay] = A;
    auto [bx, by] = B;
    auto z2 = static_cast<double>((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
    return std::sqrt(z2);
}

void readData(arDijkstra &G){
    int V, E;
    std::ifstream map_data("usa.txt");
    map_data >> V >> E;
    arMap.resize(V);
    for(size_t i = 0, id; i < V; i++){
        map_data >> id;
        map_data >> arMap[id].first >> arMap[id].second;
    }
    for(size_t i = 0; i < E; i++){
        int u, v;
        map_data >> u >> v;
        auto w = get_dis(arMap[u], arMap[v]);
        G.addEdge(u, v, w);
        G.addEdge(v, u, w);
    }
}