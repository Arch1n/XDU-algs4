//
// Created by arch0n on 18-11-12.
//

#ifndef LAB2_ARGL_H
#define LAB2_ARGL_H


#include "arOptions.h"
#include "mysort.h"

std::vector<int> arr;

void drawLines(){
    std::this_thread::sleep_for(std::chrono::milliseconds(GAP));
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
    auto& V = arr;
    for(size_t k = 0; k < V.size(); k++){
        glVertex2d(static_cast<GLdouble>(k), 0);
        glVertex2d(static_cast<GLdouble>(k), V[k]);
    }
    glEnd(); // GL_LINES
    glutSwapBuffers();
}


void ChangeSize(GLsizei w,GLsizei h) {
    h = h==0? 1: h;
    double aspectRatio = 1.0 * w / h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
        gluOrtho2D(-5.0, SIZE + 5.0, -5.0 / aspectRatio, (SIZE + 5.0) / aspectRatio);
    else
        gluOrtho2D(-5.0 * aspectRatio, (SIZE + 5.0) * aspectRatio, -5.0, SIZE + 5.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutSwapBuffers();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
    bubble::sort(arr,[](const int& a, const int& b){
        drawLines();
        return a<b;
    });
    drawLines();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    exit(EXIT_SUCCESS);
}


int arGLmain(int argc, char **argv) {
    glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB);
    glutInit(&argc, argv);
    glutInitWindowPosition(posx[5], posy[5]);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bubble sort");
    glClearColor(0.0, 0.0, 0.0, 0.0);


    arr.resize(SIZE);
    std::iota(std::begin(arr), std::end(arr), 1);
    std::random_shuffle(std::begin(arr), std::end(arr));
    glutDisplayFunc(display);
    glutReshapeFunc(ChangeSize);
    glutMainLoop();

    return 0;
}


#endif //LAB2_ARGL_H
