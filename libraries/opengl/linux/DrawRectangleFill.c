/*
 * FileName:     DrawRectangleFill
 * Author:       8ucchiman
 * CreatedDate:  2023-05-17 22:40:17
 * LastModified: 2023-02-26 13:30:39 +0900
 * Reference:    8ucchiman.jp
 * Description:  ---
 */


#include <stdio.h>
#include <GL/glut.h>
#define MACRO


void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2d(-0.9, -0.9);
    glVertex2d(0.9, -0.9);
    glVertex2d(0.9, 0.9);
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

