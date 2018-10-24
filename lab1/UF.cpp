//
// Created by arch0n on 18-10-23.
//

#include "UF.h"
#include <numeric>
#include <algorithm>
#include <cassert>

UF::UF(int n): cnt(n) {
    parent.resize(n);
    rank.resize(n);
    std::fill(rank.begin(), rank.end(), 0);
    std::iota(parent.begin(), parent.end(), 0);
}

int UF::find(int p) {
    validate(p);
    while(p != parent[p]){
        parent[p] = parent[parent[p]];
        p = parent[p];
    }
    return p;
}

void UF::validate(int idx) {
    assert(0 <= idx && idx < (int) parent.size());
}

bool UF::connected(int p, int q) {
    return find(p) == find(q);
}

void UF::uni(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);
    if(rootP == rootQ) return;
    if(rank[rootP] < rank[rootQ])
        parent[rootP] = rootQ;
    else if(rank[rootP] > rank[rootQ])
        parent[rootQ] = rootP;
    else {
        parent[rootQ] = rootP;
        rank[rootP] ++;
    }
    cnt --;
}