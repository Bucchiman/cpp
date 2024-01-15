#include <iostream>
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
 glfwTerminate();
 return 1;
 }
 // 作成したウィンドウを OpenGL の処理対象にする
 glfwMakeContextCurrent(window);
}
