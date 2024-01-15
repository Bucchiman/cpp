#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shape.h"

GLuint createProgram(const char *vsrc, const char *fsrc)
{
 // 空のプログラムオブジェクトを作成する
 const GLuint program(glCreateProgram());
 if (vsrc != NULL)
 {
 // バーテックスシェーダのシェーダオブジェクトを作成する
 const GLuint vobj(glCreateShader(GL_VERTEX_SHADER));
 glShaderSource(vobj, 1, &vsrc, NULL);
 glCompileShader(vobj);
 // バーテックスシェーダのシェーダオブジェクトをプログラムオブジェクトに組み込む
 if (printShaderInfoLog(vobj, "vertex shader"))
 glAttachShader(program, vobj);
 glDeleteShader(vobj);
 }
 if (fsrc != NULL)
 {
 // フラグメントシェーダのシェーダオブジェクトを作成する
 const GLuint fobj(glCreateShader(GL_FRAGMENT_SHADER));
 glShaderSource(fobj, 1, &fsrc, NULL);
 glCompileShader(fobj);
 // フラグメントシェーダのシェーダオブジェクトをプログラムオブジェクトに組み込む
 if (printShaderInfoLog(fobj, "fragment shader"))
 glAttachShader(program, fobj);
 glDeleteShader(fobj);
 }
 // プログラムオブジェクトをリンクする
 glBindAttribLocation(program, 0, "position");
 glBindFragDataLocation(program, 0, "fragment");
 glLinkProgram(program);
 // 作成したプログラムオブジェクトを返す
 if (printProgramInfoLog(program))
 return program;
 // プログラムオブジェクトが作成できなければ 0 を返す
 glDeleteProgram(program);
 return 0;
}


// シェーダのソースファイルを読み込んだメモリを返す
// name: シェーダのソースファイル名
// buffer: 読み込んだソースファイルのテキスト
bool readShaderSource(const char *name, std::vector<GLchar> &buffer)
{
 // ファイル名が NULL だった
 if (name == NULL) return false;
 // ソースファイルを開く
 std::ifstream file(name, std::ios::binary);
 if (file.fail())
 {
 // 開けなかった
 std::cerr << "Error: Can't open source file: " << name << std::endl;
 return false;
 }
 // ファイルの末尾に移動し現在位置（＝ファイルサイズ）を得る
 file.seekg(0L, std::ios::end);

 GLsizei length = static_cast<GLsizei>(file.tellg());
 // ファイルサイズのメモリを確保
 buffer.resize(length + 1);
 // ファイルを先頭から読み込む
 file.seekg(0L, std::ios::beg);
 file.read(buffer.data(), length);
 buffer[length] = '¥0';
 if (file.fail())
 {
 // うまく読み込めなかった
 std::cerr << "Error: Could not read souce file: " << name << std::endl;
 file.close();
 return false;
 }
 // 読み込み成功
 file.close();
 return true;
}


// シェーダのソースファイルを読み込んでプログラムオブジェクトを作成する
// vert: バーテックスシェーダのソースファイル名
// frag: フラグメントシェーダのソースファイル名
GLuint loadProgram(const char *vert, const char *frag)
{
 // シェーダのソースファイルを読み込む
 std::vector<GLchar> vsrc;
 const bool vstat(readShaderSource(vert, vsrc));
 std::vector<GLchar> fsrc;
 const bool fstat(readShaderSource(frag, fsrc));
 // プログラムオブジェクトを作成する
 return vstat && fstat ? createProgram(vsrc.data(), fsrc.data()) : 0;
}


// 矩形の頂点の位置
constexpr Object::Vertex rectangleVertex[] =
{
 { -0.5f, -0.5f },
 { 0.5f, -0.5f },
 { 0.5f, 0.5f },
 { -0.5f, 0.5f }
};



int main()
{
 // GLFW を初期化する
 if (glfwInit() == GL_FALSE)
 {
 // 初期化に失敗した
 std::cerr << "Can't initialize GLFW" << std::endl;
 return 1;
 }
 // プログラム終了時の処理を登録する
 atexit(glfwTerminate);

 // OpenGL Version 3.2 Core Profile を選択する
 glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
 glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
 glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
 glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
 // ウィンドウを作成する
 GLFWwindow *const window(glfwCreateWindow(640, 480, "Hello!", NULL, NULL));
 if (window == NULL)
 {
 // ウィンドウが作成できなかった
 std::cerr << "Can't create GLFW window." << std::endl;
 return 1;
 }
 // 作成したウィンドウを OpenGL の処理対象にする
 glfwMakeContextCurrent(window);
 // GLEW を初期化する
 glewExperimental = GL_TRUE;
 if (glewInit() != GLEW_OK)
 {
 // GLEW の初期化に失敗した
 std::cerr << "Can't initialize GLEW" << std::endl;
 return 1;
 }
 // 背景色を指定する
 glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

 const GLuint program(loadProgram("point.vert", "point.frag"));

 std::unique_ptr<const Shape> shape(new Shape(2, 4, rectangleVertex));

 // ウィンドウが開いている間繰り返す
 while (glfwWindowShouldClose(window) == GL_FALSE)
 {
 // ウィンドウを消去する
 glClear(GL_COLOR_BUFFER_BIT);
 // シェーダプログラムの使用開始
 glUseProgram(program);
 //
 // ここで描画処理を行う
 shape->draw();

 // カラーバッファを入れ替える
 glfwSwapBuffers(window);
 // イベントを取り出す
 glfwWaitEvents();
 }

}
