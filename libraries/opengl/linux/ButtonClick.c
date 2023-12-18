/*
 * FileName:     ButtonClick
 * Author:       8ucchiman
 * CreatedDate:  2023-05-18 11:24:06
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


void resize(int w, int h) {
    glViewport(0, 0, w, h);
    glLoadIdentity();
}


void mouse(int button, int state, int x, int y) {
    switch(button) {
        case GLUT_LEFT_BUTTON:
            printf("left");
            break;
        case GLUT_MIDDLE_BUTTON:
            printf("middle");
            break;
        case GLUT_RIGHT_BUTTON:
            printf("right");
            break;
        default:
            break;
    }
    printf(" button is ");
    switch (state) {
        case GLUT_UP:
            printf("up");
            break;
        case GLUT_DOWN:
            printf("down");
            break;
        default:
            break;
    }
    printf(" at (%d, %d)\n", x, y);
}

void init(void) {
    glClearColor(0.0, 0.0, 1.0, 1.0);
}

#ifdef MACRO
int main(int argc, char* argv[]){
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(320, 240);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
#endif

