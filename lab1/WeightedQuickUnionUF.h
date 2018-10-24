//
// Created by arch0n on 18-10-23.
//

#ifndef LAB1_WEIGHTEDQUICKUNIONUF_H
#define LAB1_WEIGHTEDQUICKUNIONUF_H


#include <vector>

class WeightedQuickUnionUF {
private:
    std::vector<int> parent;
    std::vector<int> size;
    int cnt;
    void validate(int);
public:
    WeightedQuickUnionUF(int);
    inline int count(){ return cnt;}
    int find(int);
    bool connected(int, int);
    void uni(int, int);
};


#endif //LAB1_WEIGHTEDQUICKUNIONUF_H
