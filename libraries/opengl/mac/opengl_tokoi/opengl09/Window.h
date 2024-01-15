#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// ウィンドウ関連の処理
class Window {
    // ウィンドウのハンドル
    GLFWwindow* const window;

    // 縦横比
    GLfloat aspect;
 // ウィンドウのサイズ
 GLfloat size[2];
 // ワールド座標系に対するデバイス座標系の拡大率
 GLfloat scale;
 // 図形の正規化デバイス座標系上での位置
 GLfloat location[2];

public:
 // コンストラクタ
 Window(int width = 640, int height = 480, const char *title = "Hello!")
 : window(glfwCreateWindow(width, height, title, NULL, NULL))
 , scale(100.0f), location{ 0.0f, 0.0f }
 {
 if (window == NULL)
 {
 // ウィンドウが作成できなかった
 std::cerr << "Can't create GLFW window." << std::endl;
 exit(1);
 }
 // 現在のウィンドウを処理対象にする
 glfwMakeContextCurrent(window);
 // GLEW を初期化する
 glewExperimental = GL_TRUE;
 if (glewInit() != GLEW_OK)
 {
 // GLEW の初期化に失敗した
 std::cerr << "Can't initialize GLEW" << std::endl;
 exit(1);
 }
 // 垂直同期のタイミングを待つ
 glfwSwapInterval(1);

 // このインスタンスの this ポインタを記録しておく
 glfwSetWindowUserPointer(window, this);

 // ウィンドウのサイズ変更時に呼び出す処理の登録
 glfwSetWindowSizeCallback(window, resize);
 // 開いたウィンドウの初期設定
 resize(window, width, height);
 }

 // デストラクタ
 virtual ~Window()
 {
 glfwDestroyWindow(window);
 }
 // 描画ループの継続判定
 explicit operator bool()
 {
 // イベントを取り出す
 glfwWaitEvents();
 // マウスカーソルの位置を取得する
 double x, y;
 glfwGetCursorPos(window, &x, &y);
 // マウスカーソルの正規化デバイス座標系上での位置を求める
 location[0] = static_cast<GLfloat>(x) * 2.0f / size[0] - 1.0f;
 location[1] = 1.0f - static_cast<GLfloat>(y) * 2.0f / size[1];

 // ウィンドウを閉じる必要がなければ true を返す
 return !glfwWindowShouldClose(window);
 }

// ダブルバッファリング
void swapBuffers() {
    // カラーバッファを入れ替える
    glfwSwapBuffers(window);
}

// ウィンドウのサイズ変更時の処理
static void resize(GLFWwindow* const window, int width, int height) {
 // フレームバッファのサイズを調べる
 int fbWidth, fbHeight;
 glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
 // フレームバッファ全体をビューポートに設定する
 glViewport(0, 0, fbWidth, fbHeight);
 // このインスタンスの this ポインタを得る
 Window *const
 instance(static_cast<Window *>(glfwGetWindowUserPointer(window)));
 if (instance != NULL)
 {
 // このインスタンスが保持する縦横比を更新する
 instance->aspect =
 static_cast<GLfloat>(width) / static_cast<GLfloat>(height);
 }
 }

 // 縦横比を取り出す
 GLfloat getAspect() const { return aspect; }

 // ウィンドウのサイズを取り出す
 const GLfloat *getSize() const { return size; }
 // ワールド座標系に対するデバイス座標系の拡大率を取り出す
 GLfloat getScale() const { return scale; }

 // 位置を取り出す
 const GLfloat *getLocation() const { return location; }

};
