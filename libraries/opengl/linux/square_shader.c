/*
 * FileName:     square_shader
 * Author:       8ucchiman
 * CreatedDate:  2023-05-26 23:24:44
 * LastModified: 2023-02-26 13:30:39 +0900
 * Reference:    8ucchiman.jp
 * Description:  ---
 */


#include <stdio.h>
#define MACRO


/** @brief Converts an image from one color space to another.

The function converts an input image from one color space to another. In case of a transformation
to-from RGB color space, the order of the channels should be specified explicitly (RGB or BGR). Note
that the default color format in OpenCV is often referred to as RGB but it is actually BGR (the
bytes are reversed). So the first byte in a standard (24-bit) color image will be an 8-bit Blue
component, the second byte will be Green, and the third byte will be Red. The fourth, fifth, and
sixth bytes would then be the second pixel (Blue, then Green, then Red), and so on.

The conventional ranges for R, G, and B channel values are:
-   0 to 255 for CV_8U images
-   0 to 65535 for CV_16U images
-   0 to 1 for CV_32F images

In case of linear transformations, the range does not matter. But in case of a non-linear
transformation, an input RGB image should be normalized to the proper value range to get the correct
results, for example, for RGB \f$\rightarrow\f$ L\*u\*v\* transformation. For example, if you have a
32-bit floating-point image directly converted from an 8-bit image without any scaling, then it will
have the 0..255 value range instead of 0..1 assumed by the function. So, before calling #cvtColor ,
you need first to scale the image down:
@code
    img *= 1./255;
    cvtColor(img, img, COLOR_BGR2Luv);
@endcode
If you use #cvtColor with 8-bit images, the conversion will have some information lost. For many
applications, this will not be noticeable but it is recommended to use 32-bit images in applications
that need the full range of colors or that convert an image before an operation and then convert
back.

If conversion adds the alpha channel, its value will set to the maximum of corresponding channel
range: 255 for CV_8U, 65535 for CV_16U, 1 for CV_32F.

@param src input image: 8-bit unsigned, 16-bit unsigned ( CV_16UC... ), or single-precision
floating-point.
@param dst output image of the same size and depth as src.
@param code color space conversion code (see #ColorConversionCodes).
@param dstCn number of channels in the destination image; if the parameter is 0, the number of the
channels is derived automatically from src and code.

@see @ref imgproc_color_conversions
 */
int hoge(void);

int hoge(void) {
    return 1;
}



/*
GLUT：四角形の描画（マテリアル）
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
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE); //ディスプレイモードの指定
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
	glClearColor(0.0, 0.0, 0.0, 1.0);              //カラーバッファーの初期値の指定（背景色）
	glEnable( GL_DEPTH_TEST );                     //デプスバッファーを有効化
	glViewport( 0, 0, WindowWidth, WindowHeight ); //ビューポートの設定

	glMatrixMode( GL_PROJECTION );  //行列モードをプロジェクション行列に指定
	glLoadIdentity();               //カレント行列の初期化
	gluPerspective(30.0, (double)WindowWidth/(double)WindowHeight, 0.1, 1000.0); //透視投影法の視体積gluPerspactive(th, w/h, near, far);
}
//--------------------------------------------------------
// アイドル時に呼び出される関数
//--------------------------------------------------------
void idle(){
	glutPostRedisplay(); //glutDisplayFunc()を１回実行する
}
//----------------------------------------------------
// 描画の関数
//----------------------------------------------------
void display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //バッファの消去
	glMatrixMode( GL_MODELVIEW ); //行列モードをモデルビュー行列に指定
	glLoadIdentity();             //カレント行列の初期化

	/////////////////////////////////////////////
	//(5) 視点の設定
	/////////////////////////////////////////////
	gluLookAt(             // 視点の設定
		   0.0, 0.0, 10.0,    // 視点の位置x,y,z;
		   0.0, 0.0, 0.0,    // 視界の中心位置の参照点座標x,y,z
		   0.0, 1.0, 0.0);   // 視界の上方向のベクトルx,y,z

	/////////////////////////////////////////////
	//(6) 光源の設定
	/////////////////////////////////////////////
	GLfloat lightAmbient[4] = {1.0,1.0,1.0,1.0};   //環境光色
	GLfloat lightDiffuse[4] = {1.0,1.0,1.0,1.0};   //拡散光色
	GLfloat lightSpecular[4] = {1.0,1.0,1.0,1.0};  //反射光色
	GLfloat lightPosition[4] = {0.0,0.0,1.0,1.0};  //光源位置
	glEnable(GL_LIGHTING);                             //光源の有効化
	glEnable(GL_LIGHT0);                               //光源0の有効化
	glLightfv( GL_LIGHT0, GL_AMBIENT,  lightAmbient);  //光源0の環境光色の指定
	glLightfv( GL_LIGHT0, GL_DIFFUSE,  lightDiffuse);  //光源0の拡散光色の指定
	glLightfv( GL_LIGHT0, GL_SPECULAR, lightSpecular); //光源0の反射光色の指定
	glLightfv( GL_LIGHT0, GL_POSITION, lightPosition); //光源0の光源位置の指定

	draw();

	glutSwapBuffers(); //glutInitDisplayMode(GLUT_DOUBLE)でダブルバッファリングを利用可
}
void draw(){
	//四角形のバッファ
	GLfloat vertices[][3] = {
		{-2.5, -2.5, 0.0}, {2.5, -2.5, 0.0}, {2.5,  2.5, 0.0}, {-2.5,  2.5, 0.0}
	};
	GLfloat normals[][3] = {
		{0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0}
	};
	GLuint indices[6] = {
		0, 1, 2, 0, 2, 3
	};

	GLfloat materialEmission[4] = {0.0,      0.0,      0.0,       1.0}; //発光色
	GLfloat materialAmbient[4]  = {0.1745,   0.01175,  0.01175,   1.0}; //環境光に対する色
	GLfloat materialDiffuse [4] = {0.61424,  0.04136,  0.04136,   1.0}; //拡散光に対する色
	GLfloat materialSpecular[4] = {0.727811, 0.626959, 0.626959,  1.0}; //反射光に対する色
	GLfloat materialShininess[1] = {76.8};                              //光沢の強度
	glMaterialfv(GL_FRONT, GL_EMISSION,  materialEmission);  //発光色の指定
	glMaterialfv(GL_FRONT, GL_AMBIENT,   materialAmbient);   //環境光に対する色の指定
	glMaterialfv(GL_FRONT, GL_DIFFUSE,   materialDiffuse);   //拡散光に対する色の指定
	glMaterialfv(GL_FRONT, GL_SPECULAR,  materialSpecular);  //反射光に対する色の指定
	glMaterialfv(GL_FRONT, GL_SHININESS, materialShininess); //光沢の強度の指定

	/////////////////////////////////////////////
	//(7) 立方体の描画
	/////////////////////////////////////////////
	glBegin(GL_TRIANGLES);        //三角形の描画
		for(int i=0; i<6; i++){
			int k = indices[i];       //頂点の指定
			glNormal3fv(normals[k]);  //法線ベクトルの指定
			glVertex3fv(vertices[k]); //頂点座標の指定
		}
	glEnd();
}

