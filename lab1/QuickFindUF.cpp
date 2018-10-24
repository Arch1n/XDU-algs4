//
// Created by arch0n on 18-10-23.
//

#include "QuickFindUF.h"
#include <cassert>

QuickFindUF::QuickFindUF(int n):cnt(n) {
    id.resize(n);
    std::iota(id.begin(), id.end(), 0);
}

void QuickFindUF::validate(int idx) {
    assert(0 <= idx && idx < (int) id.size());
}

void QuickFindUF::uni(int p, int q){
    validate(p);
    validate(q);
    int pID = find(p);
    int qID = find(q);
    if(pID == qID)
        return;
    for(auto &c:id)
        if(c == pID)
            c = qID;
}
