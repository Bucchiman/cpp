/*
GLUT：平方格子（2Dカラーマップ）
*/

#include <math.h>
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
		   0.0,  0.0, 186.0,  // 視点の位置x,y,z;
		   0.0,  0.0, 0.0,    // 視界の中心位置の参照点座標x,y,z
		   0.0,  1.0, 0.0);   // 視界の上方向のベクトルx,y,z
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
	//平方格子のサイズ
	int tate = 100, yoko = 100;
	int vertexNumber = yoko * tate ;
	int indexNumber  = 2 * (yoko-1) * (tate-1);

	GLfloat (*vertices)[3] = new GLfloat[vertexNumber][3];
	GLfloat (*colors)[4]   = new GLfloat[vertexNumber][4];
	GLuint  (*indices)[3]  = new GLuint[indexNumber][3];
	int k=0; 
	for (int i = 0; i < tate; i++) {
		for (int j = 0; j < yoko; j++) {
			//頂点配列の設定
			vertices[k][0] = i;
			vertices[k][1] = j;
			vertices[k][2] = 0.0;

			GLfloat x = GLfloat(i - tate / 2) / tate;
			GLfloat y = GLfloat(j - yoko / 2) / yoko;
			GLfloat f = exp(-10.0*(x * x + y * y));//ガウス分布
			//カラー配列の設定
			colors[k][0] = f;
			colors[k][1] = f;
			colors[k][2] = f;
			colors[k][3] = 1.0;
			k++;
		}
	}

	k=0;
	for (int i = 0; i < tate - 1; i++) {
		for (int j = 0; j < yoko - 1; j++) {
			indices[k][0] =yoko * i + j;             //三角形１の頂点１
			indices[k][1] =yoko * i + (j + 1);       //三角形１の頂点２
			indices[k][2] =yoko * (i + 1) + (j + 1); //三角形１の頂点３
			k++;
			indices[k][0] =yoko * i + j;             //三角形２の頂点１
			indices[k][1] =yoko * (i + 1) + j;       //三角形２の頂点２
			indices[k][2] =yoko * (i + 1) + (j + 1); //三角形２の頂点３
			k++;
		}
	}

	glPushMatrix();
		glTranslatef( -yoko/2+0.5, -tate/2+0.5, 0.0);     //平行移動
		glRotatef(0.0 , 0.0, 0.0, 1.0);  //回転
		//四角形の描画
		glBegin(GL_TRIANGLES);//GL_POINTS, GL_LINE_STRIP, GL_LINE_LOOP, GL_LINES, GL_TRIANGLE_STRIP, GL_TRIANGLE_FAN, GL_TRIANGLES
			for(int i=0; i<indexNumber; i++){
				for(int j=0; j<3; j++){
					int k = indices[i][j];
					glColor4fv(colors[k]);
					glVertex3fv(vertices[k]); 
				}
			}
		glEnd();
	glPopMatrix();
}

