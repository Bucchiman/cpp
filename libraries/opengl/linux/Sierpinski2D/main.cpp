/*
 * FileName:     main
 * Author:       8ucchiman
 * CreatedDate:  2025-09-06 17:33:22
 * LastModified: 2024-02-09 13:26:58
 * Reference:    8ucchiman.jp
 */


#include <iostream>
#include <cmath>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct Point {
    GLfloat x, y;
    Point(GLfloat x = 0, GLfloat y = 0): x(x), y(y) {}
    Point midpoint(Point p) {return Point((x+p.x)/2.0, (y+p.y)/2.0);}
};

static void glfw_error_callback(int code, const char* desc){
    std::fprintf(stderr, "GLFW Error %d: %s\n", code, desc);
}



int main(void) {
    glfwSetErrorCallback(glfw_error_callback);
    if(!glfwInit()) {
        std::fprintf(stderr, "Failed to init GLFW\n");
        return EXIT_FAILURE;
    }

    return 0;
}
