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
#include <thread>
#include <future>

#include "Percolation.h"


static unsigned long N;
double worker();

int main(int argc, char **argv) {
    assert(argc == 3);
    N = std::stoul(std::string(argv[1]));
    auto T = std::stoul(std::string(argv[2]));
    std::vector<std::future<double>> tasks(T);
    std::vector<double> ans(T);
    //clock_t start_time = clock();
    for(auto &th: tasks){
        std::packaged_task<double()> task (worker);
        th = task.get_future();
        std::thread(std::move(task)).detach();
    }
    for(auto &th: tasks)
        th.wait();
    for(size_t i = 0; i < T; i++)
        ans[i] = tasks[i].get();
    //clock_t end_time = clock();
    double avg = std::accumulate(ans.begin(), ans.end(), 0.0, [](double last, const auto& cur){ return last + cur;}) / ans.size();
    double var = std::accumulate(ans.begin(), ans.end(), 0.0, [avg](double last, const auto& cur){ return last + (avg-cur)*(avg-cur); }) / (ans.size()-1);
    double stddev = sqrt(var);
    auto confidence = std::make_pair(avg - 1.96 * stddev / sqrt(ans.size()), avg + 1.96 * stddev / sqrt(ans.size()));
    std::cout << "avg:\t" << avg << '\n' << "stddev:\t" << stddev << '\n' << "confidence interval: [" << confidence.first << ", " << confidence.second << "]\n";
    //std::cout << "time:\t" << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC  << " s\n";
    return 0;
}

double worker(){
    std::vector<std::pair<int, int>> list;
    for(int i=1; i<=N; i++)for(int j=1; j<=N; j++)list.emplace_back(i, j);
    Percolation exp(N);
    int cnt = 0;
    std::random_shuffle(list.begin(), list.end());
    for(const auto& c: list){
        exp.open(c.first, c.second);
        cnt ++;
        if(exp.percolates())
            break;
    }
    return 1.0 * cnt / (N*N);
}

