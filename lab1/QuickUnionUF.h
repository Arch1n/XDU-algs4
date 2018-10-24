//
// Created by arch0n on 18-10-23.
//

#ifndef LAB1_QUICKUNIONUF_H
#define LAB1_QUICKUNIONUF_H



#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>


class QuickUnionUF {
private:
    std::vector<int> parent;
    int cnt;
    void validate(int);
public:
    QuickUnionUF(int);
    inline int count(){ return cnt;}
    int find(int);
    bool connected(int, int);
    void uni(int, int);
};

#endif //LAB1_QUICKUNIONUF_H
