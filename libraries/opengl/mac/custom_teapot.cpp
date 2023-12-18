/*
 * FileName:     custom_teapot
 * Author:       8ucchiman
 * CreatedDate:  2023-08-20
 * LastModified: 2023-02-25 18:37:47 +0900
 * Reference:    8ucchiman.jp
 */


#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>
#define MACRO


const GLfloat lightPosition1[4] = {0.0f,3.0f, 5.0f, 1.0f};
const GLfloat green[] = { 0.0, 1.0, 0.0, 1.0 };
const GLfloat lightPosition2[4] = {5.0f,3.0f, 0.0f, 1.0f};
const GLfloat red[] = { 1.0, 0.0, 0.0, 1.0 };
const GLfloat teapotAmbient[4] = {0.3f,0.5f, 0.0f, 1.0f};
const GLfloat teapotDiffuse[4] = {1.0f,1.0f, 0.3f, 1.0f};
const GLfloat teapotSpecular[4] = {1.0f,1.0f, 1.0f, 1.0f};
const GLfloat teapotShininess[4] = {20.0f};
void setup(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition1);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, red);
    glLightfv(GL_LIGHT0, GL_SPECULAR, red);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPosition2);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, green);
    glLightfv(GL_LIGHT1, GL_SPECULAR, green);
    glMaterialfv(GL_FRONT, GL_AMBIENT, teapotAmbient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, teapotDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, teapotSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, teapotShininess);
}


void draw (void) {

}


void resize(int width, int height) {
}


void display (void) {

}


int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("Custom Teapot");
    glutReshapeFunc(resize);
    glutDisplayFunc(draw);
    setup();
    glutMainLoop();
    return 0;
}
