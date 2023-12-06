/*
 * FileName:     tips
 * Author:       8ucchiman
 * CreatedDate:  2023-12-06 10:36:09
 * LastModified: 2023-12-06 16:42:32
 * Reference:    8ucchiman.jp
 * Description:  ---
 */


#include <iostream>
#define MACRO

#ifdef MACRO
int main(int argc, char* argv[]){
    
    return 0;
}
#endif


/* ------------------------- */
// Reference: https://stackoverflow.com/questions/28298540/difference-between-single-bufferedglut-single-and-double-buffered-drawingglut
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
// GL_SINGLE: you can picture your code drawing directly to the display
// GL_DOUBLE: you can picture having two buffers


/* ------------------------- */
// Reference: https://www.oit.ac.jp/is/L231/~whashimo/Article/OpenGL/Chapter7/index.html
glTexCood2f(s, t);          // cut texture          left-down:(0.0, 0.0) -> (s, t) (0<s, t<1, otherwise repeat texture)
glVertex2f(s, t);           // paste texture        left-down:(0.0, 0.0) -> (s, t)

#include <GL/glut.h>
// e.g. 01
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-5.0,-5.0, 0.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-5.0, 5.0, 0.0);
    glTexCoord2f(1.0, 1.0); glVertex3f( 5.0, 5.0, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f( 5.0,-5.0, 0.0);
    glEnd();
}

// e.g. 02
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-5.0,-5.0, 0.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-5.0, 5.0, 0.0);
    glTexCoord2f(2.0, 1.0); glVertex3f( 5.0, 5.0, 0.0);
    glTexCoord2f(2.0, 0.0); glVertex3f( 5.0,-5.0, 0.0);
    glEnd();
}
