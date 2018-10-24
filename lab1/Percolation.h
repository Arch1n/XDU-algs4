//
// Created by arch0n on 18-10-23.
//

#ifndef LAB1_PERCOLATION_H
#define LAB1_PERCOLATION_H

#include <vector>
#include "UF.h"

class Percolation {
private:
    std::vector<std::vector<bool>> opened;
    int top;
    int bottom;
    int size;
    UF f;
public:
    Percolation(int);
    void open(int, int);
    bool isOpen(int, int);
    bool isFull(int, int);
    inline bool percolates(){ return f.connected(top, bottom);}
    inline int getID(int i, int j){ return (i-1) * size + j;}
};


#endif //LAB1_PERCOLATION_H
