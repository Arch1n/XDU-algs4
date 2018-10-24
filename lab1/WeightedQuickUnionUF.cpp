//
// Created by arch0n on 18-10-23.
//

#include "WeightedQuickUnionUF.h"
#include <algorithm>
#include <numeric>
#include <cassert>

WeightedQuickUnionUF::WeightedQuickUnionUF(int n):cnt(n) {
    parent.resize(n);
    size.resize(n);
    std::fill(size.begin(), size.end(), 1);
    std::iota(parent.begin(), parent.end(), 0);
}

void WeightedQuickUnionUF::validate(int idx) {
    assert(0 <= idx && idx < (int) parent.size());
}

int WeightedQuickUnionUF::find(int p) {
    validate(p);
    while(p != parent[p])
        p = parent[p];
    return p;
}

bool WeightedQuickUnionUF::connected(int p, int q) {
    return find(p) == find(q);
}

void WeightedQuickUnionUF::uni(int p, int q){
    validate(p);
    validate(q);
    int rootP = find(p);
    int rootQ = find(q);
    if(rootP == rootQ)
        return;
    if(size[p] < size[q]){
        parent[rootP] = rootQ;
        size[rootQ] += size[rootP];
    } else{
        parent[rootQ] = rootP;
        size[rootP] += size[rootQ];
    }
    cnt --;
}
