/*
 * FileName:     main
 * Author:       8ucchiman
 * CreatedDate:  2023-05-25 12:07:45
 * LastModified: 2023-02-26 13:30:39 +0900
 * Reference:    https://www.natural-science.or.jp/sources/cube_GLUT.cpp
 * Description:  ---
 */


#include <stdio.h>
#include <GL/glut.h>
#define MACRO

int WindowPositionX = 200;  // 生成するウィンドウの位置のX座標
int WindowPositionY = 100;  // 生成するウィンドウの位置のY座標
int WindowWidth = 512;      // 生成するウィンドウの幅
int WindowHeight = 512;     // 生成するウィンドウの高さ
char WindowTitle[] = "8ucchiman was here";



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

/**
 * 初期設定の関数
 */
void initialize(void);
void display(void);

/**
 * アイドル時に呼び出される関数
 */
void idle(void);
void draw(void);


#ifdef MACRO
int main(int argc, char* argv[]){
    glutInit(&argc, argv);                                      // 環境の初期化
    glutInitWindowPosition(WindowPositionX, WindowPositionY);   // ウィンドウの位置の指定
    glutInitWindowSize(WindowWidth, WindowHeight);              // ウィンドウサイズの指定
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);  // ディスプレイモードの指定
    glutCreateWindow(WindowTitle);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    initialize();
    glutMainLoop();
    return 0;
}
#endif

int hoge(void) {
    return 1;
}

void initialize(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);                          // カラーバッファの初期値の指定(背景)
    glEnable(GL_DEPTH_TEST);                                   // デプスバッファを有効か
    glViewport(0, 0, WindowWidth, WindowHeight);               // ビューポートの設定

    glMatrixMode(GL_PROJECTION);                               // 行列モードをプロジェクション行列に指定
    glLoadIdentity();                                          // カレント行列の初期化
    gluPerspective(30.0, (double)WindowWidth/(double)WindowHeight, 0.1, 1000.0);  // 透視投影法の視体積gluPerspective(th, w/h, nea, near, far)
}

void idle() {
    glutPostRedisplay();   // glutDisplayFunc()を実行
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   // バッファの消去
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(                  // 始点の設定
            5.0, 5.0, 5.0,      // 始点の位置 x, y, z
            0.0, 0.0, 0.0,      // 視界の中心位置のシャン商点座標x, y, z
            0.0, 0.0, 1.0       // 視界の上方向のベクトルx, y, z
            );
    draw();
    glutSwapBuffers();          // glutInitDisplayMode(GLUT_DOUBLE)でダブルバッファリングを利用可
}

int step = 0;
void draw() {
    step++;
    GLfloat vertices[24][3] = {
		{-1.0, -1.0,  1.0}, { 1.0, -1.0,  1.0}, { 1.0,  1.0,  1.0}, {-1.0,  1.0,  1.0}, // A面
		{-1.0, -1.0, -1.0}, {-1.0,  1.0, -1.0}, { 1.0,  1.0, -1.0}, { 1.0, -1.0, -1.0}, // B面
		{-1.0,  1.0, -1.0}, {-1.0,  1.0,  1.0}, { 1.0,  1.0,  1.0}, { 1.0,  1.0, -1.0}, // C面
		{-1.0, -1.0, -1.0}, { 1.0, -1.0, -1.0}, { 1.0, -1.0,  1.0}, {-1.0, -1.0,  1.0}, // D面
		{ 1.0, -1.0, -1.0}, { 1.0,  1.0, -1.0}, { 1.0,  1.0,  1.0}, { 1.0, -1.0,  1.0}, // E面
		{-1.0, -1.0, -1.0}, {-1.0, -1.0,  1.0}, {-1.0,  1.0,  1.0}, {-1.0,  1.0, -1.0}  // F面
    };

	GLfloat colors[24][4] = {
		{1.0, 0.0, 0.0, 1.0}, {1.0, 1.0, 0.0, 1.0}, {1.0, 1.0, 1.0, 1.0}, {1.0, 0.0, 1.0, 1.0}, // A面
		{0.0, 0.0, 0.0, 1.0}, {0.0, 0.0, 1.0, 1.0}, {0.0, 1.0, 1.0, 1.0}, {0.0, 1.0, 0.0, 1.0}, // B面
		{0.0, 0.0, 1.0, 1.0}, {1.0, 0.0, 1.0, 1.0}, {1.0, 1.0, 1.0, 1.0}, {0.0, 1.0, 1.0, 1.0}, // C面
		{0.0, 0.0, 0.0, 1.0}, {0.0, 1.0, 0.0, 1.0}, {1.0, 1.0, 0.0, 1.0}, {1.0, 0.0, 0.0, 1.0}, // D面
		{0.0, 1.0, 0.0, 1.0}, {0.0, 1.0, 1.0, 1.0}, {1.0, 1.0, 1.0, 1.0}, {1.0, 1.0, 0.0, 1.0}, // E面
		{0.0, 0.0, 0.0, 1.0}, {1.0, 0.0, 0.0, 1.0}, {1.0, 0.0, 1.0, 1.0}, {0.0, 0.0, 1.0, 1.0}  // F面
	};

	GLuint indices[36] = {
		0, 1, 2,      0,  2, 3,    // A面
		4, 5, 6,      4,  6, 7,    // B面
		8, 9, 10,     8,  10, 11,  // C面
		12, 13, 14,   12, 14, 15,  // D面
		16, 17, 18,   16, 18, 19,  // E面
		20, 21, 22,   20, 22, 23   // F面
	};

    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glRotatef(step, 0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
    for(int i=0; i<36; i++) {
        int k = indices[i];
        glColor4fv(colors[k]);
        glVertex3fv(vertices[k]);
    }
    glEnd();
    glPopMatrix();

}
