#include "arDijkstra.h"
#include <fstream>
#include <chrono>
#include <thread>
#include <GL/glut.h>

void readData(arDijkstra *&);
std::vector<point> arMap;
std::vector<size_t> drawEdge;
arDijkstra *G;

class sleep_for;

#ifdef AR_DRAW
void draw();
void changeSize(GLsizei w,GLsizei h);
#endif

int main(int argc, char** argv) {
#ifndef AR_DRAW
    std::ifstream query_data("usa-1000long.txt");
    readData(G);
    int u, v;
    auto start_time = std::chrono::system_clock::now();
    while(query_data >> u >> v){
        G->work(u, v);
    }
    auto end_time = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds> (end_time - start_time);
    std::cout << "time :" << static_cast<double> (duration.count()) / std::chrono::microseconds::period::num / std::chrono::microseconds::period::den << std::endl;
#else
    glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB);
    glutInit(&argc, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1920, 1000);
    glutCreateWindow("usa");

    glutDisplayFunc(draw);
    glutReshapeFunc(changeSize);
    glutMainLoop();

#endif
    return 0;
}

double get_dis(const point& A, const point& B){
    auto [ax, ay] = A;
    auto [bx, by] = B;
    auto z2 = static_cast<double>((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
    return std::sqrt(z2);
}
void readData(arDijkstra *& G){

    size_t V, E;
    std::ifstream map_data("usa.txt");
    map_data >> V >> E;
    arMap.resize(V);
    G = new arDijkstra(V);
    for(size_t i = 0, id; i < V; i++){
        map_data >> id;
        map_data >> arMap[id].first >> arMap[id].second;
    }
    for(size_t i = 0; i < E; i++){
        int u, v;
        map_data >> u >> v;
        auto w = get_dis(arMap[u], arMap[v]);
        G->addEdge(u, v, w);
        G->addEdge(v, u, w);
    }

}


#ifdef AR_DRAW
void draw(){

    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

    readData(G);
    glLoadIdentity();

    std::ifstream query_data("usa-100long.txt");

    int u, v;
    while(query_data >> u >> v){
        drawEdge.clear();
        glColor3d(0.0, 0.0, 0.0);
        glRectd(0.0, 0.0, 15000, 10000.0);
        glutSwapBuffers();

        glColor3d(0.6, 0.6, 0.6);
        glBegin(GL_LINES);
        for(auto e: G->edges){
            auto [from, to, dis] = e;
            glVertex2d(arMap[from].first, arMap[from].second);
            glVertex2d(arMap[to].first, arMap[to].second);
        }
        glEnd();





        G->work(u, v);

        glColor3d(1.0, 0.5, 0.0);
        glBegin(GL_LINES);
        for(auto id: drawEdge){
            auto [from, to, dis] = G->edges[id];
            glVertex2d(arMap[from].first, arMap[from].second);
            glVertex2d(arMap[to].first, arMap[to].second);
        }
        glEnd();

        glPointSize(4.0f);
        glBegin(GL_POINTS);
        glColor3d(1.0, 0.0, 0.0);
        glVertex2i(arMap[u].first, arMap[u].second);
        glVertex2i(arMap[v].first, arMap[v].second);
        glEnd();

        glBegin(GL_LINES);
        glColor3d(0.0, 1.0, 0.0);
        int i = v, j;
        do {
            j = G->fa[i];
            glVertex2i(arMap[j].first, arMap[j].second);
            glVertex2i(arMap[i].first, arMap[i].second);
            i = j;
        } while (j != u);
        glEnd();




        glutSwapBuffers();
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    }
}

void changeSize(GLsizei w,GLsizei h) {
    h = h==0? 1: h;
    double aspectRatio = 1.0 * w / h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w <= h)
        gluOrtho2D(0.0, 8000.0, 0.0, 5000.0 / aspectRatio);
    else
        gluOrtho2D(0, 8000.0 * aspectRatio, 0, 5000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

#endif