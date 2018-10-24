#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <cmath>
#include <algorithm>

#include "Percolation.h"


int main(int argc, char **argv) {
    assert(argc == 3);
    auto N = std::stoi(std::string(argv[1]));
    auto T = std::stoi(std::string(argv[2]));
    std::vector<double> ans;
    std::vector<std::pair<int, int>> list;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            list.emplace_back(i, j);
    for(int I=1; I<=T; I++){
        Percolation exp(N);
        int cnt = 0;
        std::random_shuffle(list.begin(), list.end());
        for(const auto& c: list){
            exp.open(c.first, c.second);
            cnt ++;
            if(exp.percolates())
                break;
        }
        ans.push_back(1.0 * cnt / (N*N));
    }
    double avg = std::accumulate(ans.begin(), ans.end(), 0.0) / ans.size();
    double var = std::accumulate(ans.begin(), ans.end(), 0.0, [avg](double last, auto& cur){ return last + (avg-cur)*(avg-cur); }) / (ans.size()-1);
    double stddev = sqrt(var);
    auto confidence = std::make_pair(avg - 1.96 * stddev / sqrt(ans.size()), avg + 1.96 * stddev / sqrt(ans.size()));
    std::cout << "avg:\t" << avg << '\n' << "stddev:\t" << stddev << '\n' << "confidence interval: [" << confidence.first << ", " << confidence.second << "]\n";
    return 0;
}