/*
 * FileName:     draw.c
 * Author:       8ucchiman
 * CreatedDate:  2023-02-25 18:25:13 +0900
 * LastModified: 2024-02-17 14:10:41
 * Description:  黄色い四角形を描画する
 * Reference:    8ucchiman.jp
 */


#include <GL/glut.h>

void initialize(void) {
    /* クリッピングウィンドウの設定 */
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( -100.0, 100.0, -100.0, 100.0 );
    glMatrixMode( GL_MODELVIEW );

    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
}

void display(void) {
    glClear( GL_COLOR_BUFFER_BIT );

    /* 黄色い四角形の描画 */
    glColor3f( 1.0f, 1.0f, 0.0f );
    glRectf( -80.0f, -80.0f, -20.0f, -20.0f );

    glFlush();
}

void keyboard( unsigned char c, int x, int y ) {
    if( c==27 ) exit( 0 );
}

void reshape( int w, int h ) {
}

int main( int argc, char *argv[] ) {
    glutInit( &argc, argv );

    glutInitDisplayMode( GLUT_RGB );
    glutInitWindowPosition( 100, 100 );
    glutInitWindowSize( 500, 400 );
    glutCreateWindow( argv[0] );

    glutDisplayFunc( display );
    glutKeyboardFunc( keyboard );
    glutReshapeFunc( reshape );

    initialize();
    glutMainLoop();
    return 0;
}

