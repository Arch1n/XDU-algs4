cmake_minimum_required(VERSION 3.12)
project(lab2)
set(CMAKE_BUILD_TYPE RELEASE)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -lpthread")


find_package(GLUT)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})

find_package(OpenGL)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

add_executable(lab2 main.cpp arGL.h arOptions.h mysort.h arObserver.cpp arObserver.h)
target_link_libraries(lab2 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})