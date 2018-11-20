//
// Created by arch0n on 18-11-20.
//

#ifndef LAB2_AROBSERVER_H
#define LAB2_AROBSERVER_H


#include <cstdio>
#include <unistd.h>
#include <cstdlib>
#include <cassert>

class arObserver {
int pid;
public:
    arObserver();
    int get_proc_mem();
    int get_proc_virtualmem();
};


#endif //LAB2_AROBSERVER_H
