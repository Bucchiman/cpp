/*
 * FileName:     3D_cube
 * Author:       8ucchiman
 * CreatedDate:  2023-05-18 11:39:59
 * LastModified: 2023-02-26 13:30:39 +0900
 * Reference:    8ucchiman.jp
 * Description:  ---
 */


#include <stdio.h>
#include <GL/glut.h>
#define MACRO

GLdouble vertex[][3] = {
  { 0.0, 0.0, 0.0 },
  { 1.0, 0.0, 0.0 },
  { 1.0, 1.0, 0.0 },
  { 0.0, 1.0, 0.0 },
  { 0.0, 0.0, 1.0 },
  { 1.0, 0.0, 1.0 },
  { 1.0, 1.0, 1.0 },
  { 0.0, 1.0, 1.0 }
};

int edge[][2] = {
  { 0, 1 },
  { 1, 2 },
  { 2, 3 },
  { 3, 0 },
  { 4, 5 },
  { 5, 6 },
  { 6, 7 },
  { 7, 4 },
  { 0, 4 },
  { 1, 5 },
  { 2, 6 },
  { 3, 7 }
};

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    for (int i=0; i<12; ++i) {
        glVertex3dv(vertex[edge[i][0]]);
        glVertex3dv(vertex[edge[i][1]]);
    }
    glEnd();
    glFlush();
}

void resize(int w, int h) {
    glViewport(0, 0, w, h);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);
}

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

#ifdef MACRO
int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    init();
    glutMainLoop();
    return 0;
}
#endif

