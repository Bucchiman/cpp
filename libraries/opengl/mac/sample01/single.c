/*
** single.c - シングルバッファでアニメーションを行なう
*/

#include <GL/glut.h>

void initialize(void) {
    glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
}

void display(void) {
    /* アニメーション用変数 */
    static float offsetX = -1.0;

    /* アニメーション用変数の計算 (offsetX: 0.0~99.0) */
    offsetX += 1.0;
    if( offsetX>=100.0 ) offsetX -= 100.0;

    glClear( GL_COLOR_BUFFER_BIT );

    glColor3f( 1.0f, 1.0f, 0.0f );

    /* offsetX 分ずれた長方形を描画 */
    glRectf( -80.0f+offsetX, -80.0f, -20.0f+offsetX, -20.0f );

    glFlush();
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

/* アニメーション描画処理 */
void animate(void) {
    glutPostRedisplay();
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

    /* アニメーション描画処理ルーチンを
    アイドリングルーチンとして設定 */
    glutIdleFunc( animate );

    initialize();
    glutMainLoop();
    return 0;
}

