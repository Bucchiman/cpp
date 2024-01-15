// p56
// g++-mp-13 -o main main.cpp -lglfw -lGLEW -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
#include <cstdlib>
#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// シェーダオブジェクトのコンパイル結果を表示する
// shader: シェーダオブジェクト名
// str: コンパイルエラーが発生した場所を示す文字列
GLboolean printShaderInfoLog(GLuint shader, const char *str)
{
 // コンパイル結果を取得する
 GLint status;
 glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
 if (status == GL_FALSE) std::cerr << "Compile Error in " << str << std::endl;
 // シェーダのコンパイル時のログの長さを取得する
 GLsizei bufSize;
 glGetShaderiv(shader, GL_INFO_LOG_LENGTH , &bufSize);
 if (bufSize > 1)
 {
 // シェーダのコンパイル時のログの内容を取得する
 std::vector<GLchar> infoLog(bufSize);
 GLsizei length;
 glGetShaderInfoLog(shader, bufSize, &length, &infoLog[0]);
 std::cerr << &infoLog[0] << std::endl;
 }
 return static_cast<GLboolean>(status);
}

// プログラムオブジェクトのリンク結果を表示する
// program: プログラムオブジェクト名
GLboolean printProgramInfoLog(GLuint program)
{
 // リンク結果を取得する
 GLint status;
 glGetProgramiv(program, GL_LINK_STATUS, &status);
 if (status == GL_FALSE) std::cerr << "Link Error." << std::endl;
 // シェーダのリンク時のログの長さを取得する
 GLsizei bufSize;
 glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufSize);
 if (bufSize > 1)
 {
 // シェーダのリンク時のログの内容を取得する
 std::vector<GLchar> infoLog(bufSize);
 GLsizei length;
 glGetProgramInfoLog(program, bufSize, &length, &infoLog[0]);
 std::cerr << &infoLog[0] << std::endl;
 }
 return static_cast<GLboolean>(status);
}


// プログラムオブジェクトを作成する
// vsrc: バーテックスシェーダのソースプログラムの文字列
// fsrc: フラグメントシェーダのソースプログラムの文字列
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
 // 垂直同期のタイミングを待つ
 glfwSwapInterval(1);

 // 背景色を指定する
 glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

 // バーテックスシェーダのソースプログラム
 static constexpr GLchar vsrc[] =
 "#version 150 core\n"
 "in vec4 position;\n"
 "void main()\n"
 "{\n"
 " gl_Position = position;\n"
 "}\n";
 // フラグメントシェーダのソースプログラム
 static constexpr GLchar fsrc[] =
 "#version 150 core\n"
 "out vec4 fragment;\n"
 "void main()\n"
 "{\n"
 " fragment = vec4(1.0, 0.0, 0.0, 1.0);\n"
 "}\n";
 // プログラムオブジェクトを作成する
 const GLuint program(createProgram(vsrc, fsrc));


 // ウィンドウが開いている間繰り返す
 while (glfwWindowShouldClose(window) == GL_FALSE)
 {
 // ウィンドウを消去する
 glClear(GL_COLOR_BUFFER_BIT);
 //
 // ここで描画処理を行う
 // シェーダプログラムの使用開始
 glUseProgram(program);

 // カラーバッファを入れ替える
 glfwSwapBuffers(window);
 // イベントを取り出す
 glfwWaitEvents();
 }
}