/*
 * FileName:     OpenWindow
 * Author:       8ucchiman
 * CreatedDate:  2023-05-17 22:06:34
 * LastModified: 2023-03-28 10:34:14 +0900
 * Reference:    8ucchiman.jp
 * Description:  ---
 */


#include <stdio.h>
#include <GL/glut.h>

void display(void) {
}


int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

