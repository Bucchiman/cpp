/*
** stipple.c - glLineStipple() を使った描画
*/

#include <GL/glut.h>

void initialize(void) {
    /* ラインパターンの初期化 */
    glLineWidth( 5.0 );
    glLineStipple( 5, 0xf0f0 );
    glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    glEnable( GL_LINE_STIPPLE );

    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
}

void drawTri( float offset ) {
    glBegin( GL_TRIANGLES );
    glColor3f( 1.0f, 0.0f, 0.0f );
    glVertex2f( -80.0f+offset, -80.0f);
    glColor3f( 0.0f, 1.0f, 0.0f );
    glVertex2f( -20.0+offset, -70.0);
    glColor3f( 0.0f, 0.0f, 1.0f );
    glVertex2f( -40.0f+offset, -20.0f);
    glEnd();
}

void display(void) {
    static float offsetX = -1.0f;

    offsetX += 1.0f;
    if( offsetX>=100.0f ) offsetX -= 100.0f;

    glClear( GL_COLOR_BUFFER_BIT );

    glColor3f( 1.0f, 1.0f, 0.0f );


    drawTri( offsetX );

    glutSwapBuffers();
}

void keyboard( unsigned char c, int x, int y ) {
    if( c==27 ) exit( 0 );
}

void reshape( int w, int h ) {
    glViewport( 0, 0, w, h );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( -100.0, 100.0, -100.0, 100.0 );
    glMatrixMode( GL_MODELVIEW );
}

void animate(void) {
    glutPostRedisplay();
}

int main( int argc, char *argv[] ) {
    glutInit( &argc, argv );

    glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition( 100, 100 );
    glutInitWindowSize( 500, 400 );
    glutCreateWindow( argv[0] );

    glutDisplayFunc( display );
    glutKeyboardFunc( keyboard );
    glutReshapeFunc( reshape );
    glutIdleFunc( animate );

    initialize();
    glutMainLoop();
    return 0;
}

