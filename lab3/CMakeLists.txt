cmake_minimum_required(VERSION 3.12)
project(lab3)

set(CMAKE_CXX_STANDARD 17)

find_package(GLUT)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})

find_package(OpenGL)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

add_executable(lab3 main.cpp arGraph.cpp arGraph.h arDijkstra.cpp arDijkstra.h)
target_link_libraries(lab3 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
