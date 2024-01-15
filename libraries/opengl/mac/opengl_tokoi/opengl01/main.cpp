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
}
