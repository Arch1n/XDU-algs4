cmake_minimum_required(VERSION 3.12)
project(lab1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -lpthread")


add_executable(lab1 main.cpp QuickFindUF.cpp QuickFindUF.h QuickUnionUF.cpp QuickUnionUF.h WeightedQuickUnionUF.cpp WeightedQuickUnionUF.h UF.cpp UF.h Percolation.cpp Percolation.h)