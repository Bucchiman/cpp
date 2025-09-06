/*
 * FileName:     primitive
 * Author:       8ucchiman
 * CreatedDate:  2023-02-25 18:25:13 +0900
 * LastModified: 2024-02-17 15:46:06
 * Description:  glBegin()、glEnd() を使った描画
 * Reference:    8ucchiman.jp
 */


#include <GL/glut.h>

void initialize(void) {
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
}

/* 三角形の描画 */
void drawTri( float offset ) {
    /* プリミティブ描画関数による三角形の描画 */
    glBegin( GL_TRIANGLES );
    /* 赤い頂点 */
    glColor3f( 1.0f, 0.0f, 0.0f );
    glVertex2f( -80.0f+offset, -80.0f);

    /* 緑の頂点 */
    glColor3f( 0.0f, 1.0f, 0.0f );
    glVertex2f( -20.0+offset, -70.0);

    /* 青い頂点 */
    glColor3f( 0.0f, 0.0f, 1.0f );
    glVertex2f( -40.0f+offset, -20.0f);
    glEnd();
}

void display(void) {
    static float offsetX = -1.0;

    offsetX += 1.0;
    if( offsetX>=100.0 ) offsetX -= 100.0;

    glClear( GL_COLOR_BUFFER_BIT );

    glColor3f( 1.0f, 1.0f, 0.0f );

    /* offsetX 分ずれた三角形を描画 */
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

