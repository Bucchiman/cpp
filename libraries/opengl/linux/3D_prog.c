/*
 * FileName:     3D_prog
 * Author:       8ucchiman
 * CreatedDate:  2023-05-18 11:33:41
 * LastModified: 2023-02-26 13:30:39 +0900
 * Reference:    8ucchiman.jp
 * Description:  ---
 */


#include <stdio.h>
#include <GL/glut.h>
#define MACRO


void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glRotated(25.0, 0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glColor3d(1.0, 0.0, 0.0);
    glVertex2d(-0.9, -0.9);
    glColor3d(0.0, 1.0, 0.0);
    glVertex2d(0.9, -0.9);
    glColor3d(0.0, 0.0, 1.0);
    glVertex2d(0.9, 0.9);
    glColor3d(1.0, 1.0, 0.0);
    glVertex2d(-0.9, 0.9);
    glEnd();
    glFlush();
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
    init();
    glutMainLoop();
    return 0;
}
#endif

