// g++ -o main main.cpp -lglfw -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
int main()
{
 // GLFW を初期化する
 if (glfwInit() == GL_FALSE)
 {
 // 初期化に失敗した
 std::cerr << "Can't initialize GLFW" << std::endl;
 return 1;
 }

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
 // ウィンドウが開いている間繰り返す
 while (glfwWindowShouldClose(window) == GL_FALSE)
 {
 // ウィンドウを消去する
 glClear(GL_COLOR_BUFFER_BIT);
 //
 // ここで描画処理を行う
 //
 // カラーバッファを入れ替える
 glfwSwapBuffers(window);
 // イベントを取り出す
 glfwWaitEvents();
 }
}