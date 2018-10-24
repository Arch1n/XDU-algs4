//
// Created by arch0n on 18-10-23.
//

#include "QuickUnionUF.h"
#include <cassert>

QuickUnionUF::QuickUnionUF(int n):cnt(n) {
    parent.resize(n);
    std::iota(parent.begin(), parent.end(), 0);
}

int QuickUnionUF::find(int p) {
    validate(p);
    while(p != parent[p])
        p = parent[p];
    return p;
}

void QuickUnionUF::validate(int idx) {
    assert(0 <= idx && idx < (int) parent.size());
}


bool QuickUnionUF::connected(int p, int q) {
    return find(p) == find(q);
}

void QuickUnionUF::uni(int p, int q){
    validate(p);
    validate(q);
    int rootP = find(p);
    int rootQ = find(q);
    if(rootP == rootQ)
        return;
    parent[rootP] = rootQ;
    cnt --;
}