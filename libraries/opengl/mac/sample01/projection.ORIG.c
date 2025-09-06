/*
** projection.c - 投影変換のみの 3 次元グラフィックス
*/

#include <GL/glut.h>
#include "./laconia.h" /* セミナー用 3 次元基本形状 */

void initialize(void) {
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
}

void display(void) {
    glClear( GL_COLOR_BUFFER_BIT );

    glColor3f( 1.0f, 1.0f, 0.0f );

    /* 球の描画 */
    lacSphere( 10.0, 'w' );

    glutSwapBuffers();
}

void keyboard( unsigned char c, int x, int y ) {
    if( c==27 ) exit( 0 );
}

void reshape( int w, int h ) {
    glViewport( 0, 0, w, h );

    /* 3 次元投影マトリックスの設定 */
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 45.0, 1.0, 1.0, 1000.0 );
    glMatrixMode( GL_MODELVIEW );
}

void animate(void) {
    /* 演習で、毎ループ reshape 関数を使って投影変換のパラメータが、
    更新されるようにするため、ここで reshape を呼んでいる。
    演習のとき以外は reshape を呼ぶ必要はない。 */
    reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
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
