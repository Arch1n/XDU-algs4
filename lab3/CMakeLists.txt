cmake_minimum_required(VERSION 3.12)
project(lab3)
#add_definitions(-D AR_DRAW)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)

find_package(GLUT)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})

find_package(OpenGL)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
add_executable(lab3 main.cpp arGraph.cpp arGraph.h arDijkstra.cpp arDijkstra.h)
target_link_libraries(lab3 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
