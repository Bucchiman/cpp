/*
 * FileName:     main
 * Author:       8ucchiman
 * CreatedDate:  2023-07-24 00:28:03
 * LastModified: 2023-02-26 13:30:39 +0900
 * Reference:    https://www.natural-science.or.jp/laboratory/opengl_intro.php
 * Description:  ---
 */


/*
GLUT：四角形の描画
*/
#include <GL/glut.h>

int WindowPositionX = 200;  //生成するウィンドウ位置のX座標
int WindowPositionY = 100;  //生成するウィンドウ位置のY座標
int WindowWidth  = 512;     //生成するウィンドウの幅
int WindowHeight = 512;     //生成するウィンドウの高さ
char WindowTitle[] = "世界の始まり";	//ウィンドウのタイトル

//----------------------------------------------------
// 関数プロトタイプ（後に呼び出す関数名と引数の宣言）
//----------------------------------------------------
void initialize(void);
void display(void);
void idle(void);
void draw(void);
//----------------------------------------------------
// メイン関数
//----------------------------------------------------
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);                                     //環境の初期化
	glutInitWindowPosition(WindowPositionX, WindowPositionY);  //ウィンドウの位置の指定
	glutInitWindowSize(WindowWidth, WindowHeight);             //ウィンドウサイズの指定
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);              //ディスプレイモードの指定
	glutCreateWindow(WindowTitle);                             //ウィンドウの作成
	glutDisplayFunc(display);                                  //描画時に呼び出される関数を指定する（関数名：display）
	glutIdleFunc(idle);                                        //プログラムアイドル状態時に呼び出される関数
	initialize();                                              //初期設定の関数を呼び出す
	glutMainLoop();
	return 0;
}
//----------------------------------------------------
// 初期設定の関数
//----------------------------------------------------
void initialize(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0); //背景色
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective(30.0, (double)WindowWidth/(double)WindowHeight, 0.1, 1000.0); //透視投影法の視体積gluPerspactive(th, w/h, near, far);

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	gluLookAt(
		   10.0, 0.0, 0.0,    // 視点の位置x,y,z;
		   0.0,  0.0, 0.0,    // 視界の中心位置の参照点座標x,y,z
		   0.0,  0.0, 1.0);   // 視界の上方向のベクトルx,y,z
}
//--------------------------------------------------------
// アイドル時に呼び出される関数
//--------------------------------------------------------
void idle()
{
	glutPostRedisplay(); //glutDisplayFunc()を１回実行する
}
//----------------------------------------------------
// 描画の関数
//----------------------------------------------------
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //バッファの消去

	draw();

	glutSwapBuffers(); //glutInitDisplayMode(GLUT_DOUBLE)でダブルバッファリングを利用可
}
void draw()
{
	GLfloat vertices[4][3] = { 
		{0.0, -2.5, -2.5}, { 0.0,  2.5, -2.5}, { 0.0,  2.5,  2.5}, {0.0, -2.5,  2.5}
	};
	GLfloat colors[4][4] = {
		{1.0, 0.0, 0.0, 1.0}, {0.0, 1.0, 0.0, 1.0}, {0.0, 0.0, 1.0, 1.0}, {1.0, 0.0, 1.0, 1.0}, 
	};
	glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);     //平行移動
		glRotatef(0.0 , 0.0, 0.0, 1.0);  //回転
		//四角形の描画
		glBegin(GL_QUADS);//GL_POINTS, GL_LINE_STRIP, GL_LINE_LOOP, GL_LINES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_TRIANGLES
			for(int i=0; i<4; i++){
				glColor4fv(colors[i]); glVertex3fv(vertices[i]); 
			}
		glEnd();
	glPopMatrix();
}
