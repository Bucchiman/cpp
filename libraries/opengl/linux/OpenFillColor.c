/*
 * FileName:     OpenFillColor
 * Author:       8ucchiman
 * CreatedDate:  2023-05-17 22:13:40
 * LastModified: 2023-02-26 13:30:39 +0900
 * Reference:    8ucchiman.jp
 * Description:  ---
 */


#include <stdio.h>
#include <GL/glut.h>
#define MACRO


void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void init(void) {
    glClearColor(0.0, 0.0, 1.0, 1.0);
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
