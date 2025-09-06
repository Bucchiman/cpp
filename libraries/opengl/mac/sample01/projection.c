#include <GL/glut.h>

void initialize(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 0.0f);

    // Draw a sphere at the origin with radius 1.0
    glutSolidSphere(1.0, 20, 20);

    glutSwapBuffers();
}

void keyboard(unsigned char c, int x, int y) {
    if (c == 27) exit(0);
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);

    // 3 次元投影マトリックスの設定
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
}

void animate(void) {
    glutPostRedisplay();
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 400);
    glutCreateWindow(argv[0]);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutIdleFunc(animate);

    initialize();
    glutMainLoop();
    return 0;
}
