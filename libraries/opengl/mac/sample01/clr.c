/*
 * FileName:     clr.c
 * Author:       8ucchiman
 * CreatedDate:  2023-02-25 18:25:13 +0900
 * LastModified: 2024-02-17 13:37:46
 * Description:  画面を黒でクリアする
 * Reference:    8ucchiman.jp
 */

#include <GL/glut.h> /* GLUT ライブラリ用 */

/* 初期化 */
void initialize(void) {
    /* 画面クリアカラーの設定 */
    glClearColor( 100.0f, 200.0f, 0.0f, 1.0f );
}

/* 描画 */
void display(void) {
    /* 画面クリア */
    glClear( GL_COLOR_BUFFER_BIT );

    /* 描画終了 */
    glFlush();
}

/* キーボード入力処理 */
void keyboard( unsigned char c, int x, int y ) {
    /* ESC キー (コード 27) でプログラム終了 */
    if( c==27 ) exit( 0 );
}

/* ウィンドウ変形処理 */
void reshape( int w, int h ) {
    /* 何もしない */
}

int main( int argc, char *argv[] ) {
    /* glut のイニシャライズ */
    glutInit( &argc, argv );

    /* ウィンドウの生成 */
    glutInitDisplayMode( GLUT_RGB );
    glutInitWindowPosition( 10, 100 );
    glutInitWindowSize( 1000, 400 );
    glutCreateWindow( argv[0] );

    /* 描画ルーチンの設定 */
    glutDisplayFunc( display );

    /* キーボード入力処理ルーチンの設定 */
    glutKeyboardFunc( keyboard );

    /* ウィンドウ変形処理ルーチンの設定 */
    glutReshapeFunc( reshape );

    /* OpenGL 初期化ルーチンの呼び出し */
    initialize();

    /* 無限ループ */
    glutMainLoop();
    return 0;
}

