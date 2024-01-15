// reference: https://web.wakayama-u.ac.jp/~wuhy/GSS/05.html
// gcc -no-pie -std=c++11 -o prog06 prog06.c -lGLUT -lglfw -lGLEW -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo


#include <GLUT/glut.h>
#include <stdlib.h>

/* マシンの処理速度の差の調整用パラメタ */
#define  adjust_r  5

GLdouble vertex[][3] = {
  /* 変更なし */
};

int edge[][2] = {
  /* 変更なし */
};

void display(void)
{
  int i;
  static int r = 0; /* 回転角 */

  glClear(GL_COLOR_BUFFER_BIT);

  glLoadIdentity();

  /* 視点位置と視線方向 */
  gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  /* 図形の回転 */
  glRotated((double)r/adjust_r, 0.0, 1.0, 0.0);

  /* 図形の描画 */
  glColor3d(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  for (i = 0; i < 12; i++) {
    glVertex3dv(vertex[edge[i][0]]);
    glVertex3dv(vertex[edge[i][1]]);
  }
  glEnd();

  glFlush();

  /* 回転の制御 */
  /* 処理対象のウィンドウの関係するレイヤの状態を調べる */
  if (glutLayerGet(GLUT_NORMAL_DAMAGED) == 0) {
    /* glutPostRedisplay() による再描画 */
    if (r++ >= 360*adjust_r) {
      /* 一周回ったらアニメーションを止める */
      r = 0;
      glutIdleFunc(0);
    }
  }
}

void idle(void)
{
  glutPostRedisplay();
}

void resize(int w, int h)
{
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  /* ウィンドウ全体をビューポートにする */
  glMatrixMode(GL_PROJECTION);          /* 投影変換行列の設定 */
  glLoadIdentity();                     /* 変換行列の初期化 */
  gluPerspective(30.0, (double)w/(double)h, 3.0, 10.0);
  glMatrixMode(GL_MODELVIEW);           /* モデルビュー変換行列の設定 */
  /* 削除
   glLoadIdentity();
   gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  */
  
}

void keyboard(unsigned char key, int x, int y)
{
  /* 変更なし */
}

void mouse(int button, int state, int x, int y)
{
  switch (button) {
  case GLUT_LEFT_BUTTON:
    /* アニメーション開始 */
    if (state == GLUT_UP) glutIdleFunc(idle);
    break;
  case GLUT_MIDDLE_BUTTON:
    /* コマ送り */
    if (state == GLUT_UP) glutPostRedisplay();
    break;
  case GLUT_RIGHT_BUTTON:
    /* アニメーション停止 */
    /* プログラムが「何もすることがない」ときに実行する関数のポインタを指定 */
    if (state == GLUT_UP) glutIdleFunc(NULL);
    break;
  default:
    break;
  }
}

void init(void)
{
  /* 変更なし */
}

int main(int argc, char** argv)
{
  /* 初期化 */
  glutInit(&argc, argv);

  /* ウィンドウの生成 */
  glutInitDisplayMode(GLUT_RGBA);
  glutInitWindowPosition(200, 50);
  glutInitWindowSize(300, 300);
  glutCreateWindow(argv[0]);

  /* OpenGL 初期化ルーチンの呼出し */
  init();

  /* 描画ルーチンの設定 */
  glutDisplayFunc(display);
  glutReshapeFunc(resize);

  /* 入力処理ルーチンの設定 */
  glutKeyboardFunc( keyboard );
  glutMouseFunc(mouse);

  /* 無限ループ */
  glutMainLoop();
  return 0;
}
