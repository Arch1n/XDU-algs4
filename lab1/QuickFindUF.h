//
// Created by arch0n on 18-10-23.
//

#ifndef LAB1_QUICKFINDUF_H
#define LAB1_QUICKFINDUF_H


#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>


class QuickFindUF {
private:
    std::vector<int> id;
    int cnt;
    void validate(int);
public:
    QuickFindUF(int);
    inline int count(){ return cnt;}
    inline int find(int p){ return validate(p),id[p];}
    void uni(int, int);
};




#endif //LAB1_QUICKFINDUF_H
