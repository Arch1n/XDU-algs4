//
// Created by arch0n on 18-10-23.
//

#ifndef LAB1_UF_H
#define LAB1_UF_H


#include <vector>
#include "QuickUnionUF.h"
#include "QuickFindUF.h"
#include "WeightedQuickUnionUF.h"

class UF {
private:
    std::vector<int> parent;
    std::vector<int> rank;
    int cnt;
    void validate(int);
public:
    UF(int);
    int find(int);
    inline int count(){ return cnt;}
    bool connected(int, int);
    void uni(int, int);
};


#endif //LAB1_UF_H
