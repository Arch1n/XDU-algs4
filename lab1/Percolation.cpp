//
// Created by arch0n on 18-10-23.
//

#include "Percolation.h"
#include <algorithm>
#include <cstdlib>

Percolation::Percolation(int N): size(N), f(N*N+2) {
    top = 0;
    bottom = size * size + 1;
    opened.resize(size);
    for(auto &c: opened){
        c.resize(size);
        std::fill(c.begin(), c.end(), 0);
    }
}

void Percolation::open(int i, int j) {
    opened[i - 1][j - 1] = true;
    if(i == 1)
        f.uni(getID(i, j), top);
    if(i == size)
        f.uni(getID(i, j), bottom);
    if(j > 1 && isOpen(i, j-1))
        f.uni(getID(i, j), getID(i, j-1));

    if(j < size && isOpen(i, j+1))
        f.uni(getID(i, j), getID(i, j+1));

    if(i > 1 && isOpen(i-1, j))
        f.uni(getID(i, j), getID(i-1, j));

    if(i < size && isOpen(i+1, j))
        f.uni(getID(i, j), getID(i+1, j));

}

bool Percolation::isOpen(int i, int j) {
    return opened[i - 1][j - 1];
}

bool Percolation::isFull(int i, int j) {
    if(0<i && i<=size && 0<j && j<=size){
        return f.connected(top, getID(i, j));
    } else
        exit(EXIT_FAILURE);
}