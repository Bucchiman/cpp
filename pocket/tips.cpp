/*
 * FileName:     tips
 * Author:       8ucchiman
 * CreatedDate:  2023-12-06 10:36:09
 * LastModified: 2023-12-17 13:59:52
 * Reference:    8ucchiman.jp
 * Description:  ---
 */


#include <iostream>
#define MACRO

#ifndef MACRO
int main(int argc, char* argv[]){
    
    return 0;
}
#endif


/* ------------------------- */
#ifndef MACRO
// Reference: https://stackoverflow.com/questions/28298540/difference-between-single-bufferedglut-single-and-double-buffered-drawingglut
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
// GL_SINGLE: you can picture your code drawing directly to the display
// GL_DOUBLE: you can picture having two buffers
#endif

/* ------------------------- */
#ifndef MACRO
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
#endif

#ifndef MACROX
#include <stdio.h>
[event_source(native)]
class CSource {
    public:
        __event void MyEvent(int nValue);
};

[event_receiver(native)]
class CReceiver {
    public:
        void MyHandler1(int nValue) {
            prinf_s("MyHandler1 was called with value %d.\n", nValue);
        }

        void MyHandler2(int nValue) {
            prinf_s("MyHandler2 was called with value %d.\n", nValue);
        }


        void hookEvent(CSource* pSource) {
            __hook(&CSource::MyEvent, pSource, &CReceiver::MyHandler1);
            __hook(&CSource::MyEvent, pSource, &CReceiver::MyHandler2);
        }

        void unhookEvent(CSource* pSource) {
            __unhook(&CSource::MyEvent, pSource, &CReceiver::MyHandler1);
            __unhook(&CSource::MyEvent, pSource, &CReceiver::MyHandler2);
        }
};


int main() {
    CSource source;
    CReceiver receiver;

    receiver.hookEvent(&source);
    __raise source.MyEvent(123);
    receiver.unhookEvent(&source);
}
#endif
