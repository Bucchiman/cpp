/*
 * FileName:     exercise01
 * Author:       8ucchiman
 * CreatedDate:  2023-05-18 17:05:43
 * LastModified: 2023-02-26 13:30:39 +0900
 * Reference:    http://www.oit.ac.jp/is/L231/~whashimo/Article/OpenGL/Chapter4/
 * Description:  ---
 */


#include <GL/glut.h>
#include <stdlib.h>

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -100.0);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidTeapot(50.0);
	glFlush();
 	glutSwapBuffers();
}

void init(void) {
  glClearColor (0.0, 0.0, 0.0, 0.0);               /*黒で画面クリア*/
  glShadeModel (GL_SMOOTH);                        /*フラットシェーディング*/
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h) {                       /*画面サイズ変更時に呼ばれる*/
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);     /*画面の出る範囲*/
   glMatrixMode(GL_PROJECTION);                    /*視界変換宣言*/
   glLoadIdentity();                               /*単位行列代入*/
   glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 10000.0);  /*視体積の設定*/
     glMatrixMode(GL_MODELVIEW);                   /*モデル変換宣言*/
   glLoadIdentity();                               /*単位行列代入*/
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);                                     /*GLUT初期化*/
   glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
   glutInitWindowSize (500, 500);                             /*画面の大きさ設定*/
   glutInitWindowPosition (100, 100);                         /*画面の位置設定*/
   glutCreateWindow (argv[0]);                                /*引数の名前のウインドウ作成*/
   init ();
   glutIdleFunc(display);                                     /*アイドル時に呼ぶ関数*/
   glutDisplayFunc(display);                                  /*表示時に呼ぶ関数*/
   glutReshapeFunc(reshape);                                  /*画面サイズ変更時に呼ぶ関数*/
   glutMainLoop();                                            /*描画開始*/
   return 0;
}
