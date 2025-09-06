/*
 * FileName:     main
 * Author:       8ucchiman
 * CreatedDate:  2025-08-31 12:52:59
 * LastModified: 2024-11-24 14:51:30
 * Reference:    8ucchiman.jp
 */

// main.cpp
// Rewrite of legacy GLUT sample to modern OpenGL (GLFW + GLAD + GLM)

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <string>
#include <array>

// #include </home/bucchiman/source/glad/include/glad/glad.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// ====== 旧コードの定数を踏襲 ======
int WindowPositionX = 200;
int WindowPositionY = 100;
int WindowWidth     = 512;
int WindowHeight    = 512;
const char* WindowTitle = "8ucchiman was here (Modern OpenGL)";

// ====== シェーダ（頂点＆フラグメント） ======
static const char* kVS = R"(#version 330 core
layout (location = 0) in vec3 inPos;
layout (location = 1) in vec4 inColor;

uniform mat4 uMVP;

out vec4 vColor;
void main(){
    vColor = inColor;
    gl_Position = uMVP * vec4(inPos, 1.0);
}
)";

static const char* kFS = R"(#version 330 core
in vec4 vColor;
out vec4 FragColor;
void main(){
    FragColor = vColor;
}
)";

// ====== ユーティリティ ======
static void glfw_error_callback(int code, const char* desc){
    std::fprintf(stderr, "GLFW Error %d: %s\n", code, desc);
}

static GLuint compile_shader(GLenum type, const char* src){
    GLuint sh = glCreateShader(type);
    glShaderSource(sh, 1, &src, nullptr);
    glCompileShader(sh);
    GLint ok = 0;
    glGetShaderiv(sh, GL_COMPILE_STATUS, &ok);
    if(!ok){
        GLint len = 0; glGetShaderiv(sh, GL_INFO_LOG_LENGTH, &len);
        std::string log(len, '\0');
        glGetShaderInfoLog(sh, len, nullptr, log.data());
        std::fprintf(stderr, "Shader compile error:\n%s\n", log.c_str());
        std::exit(EXIT_FAILURE);
    }
    return sh;
}

static GLuint link_program(GLuint vs, GLuint fs){
    GLuint prog = glCreateProgram();
    glAttachShader(prog, vs);
    glAttachShader(prog, fs);
    glLinkProgram(prog);
    GLint ok = 0;
    glGetProgramiv(prog, GL_LINK_STATUS, &ok);
    if(!ok){
        GLint len = 0; glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &len);
        std::string log(len, '\0');
        glGetProgramInfoLog(prog, len, nullptr, log.data());
        std::fprintf(stderr, "Program link error:\n%s\n", log.c_str());
        std::exit(EXIT_FAILURE);
    }
    glDetachShader(prog, vs);
    glDetachShader(prog, fs);
    glDeleteShader(vs);
    glDeleteShader(fs);
    return prog;
}

// ====== リサイズでビューポート更新 ======
static void framebuffer_size_callback(GLFWwindow*, int w, int h){
    glViewport(0, 0, w, h);
}

// ====== メイン ======
int main(void){
    glfwSetErrorCallback(glfw_error_callback);
    if(!glfwInit()){
        std::fprintf(stderr, "Failed to init GLFW\n");
        return EXIT_FAILURE;
    }

    // OpenGL 3.3 Core Profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#if __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    GLFWwindow* win = glfwCreateWindow(WindowWidth, WindowHeight, WindowTitle, nullptr, nullptr);
    if(!win){
        std::fprintf(stderr, "Failed to create window\n");
        glfwTerminate();
        return EXIT_FAILURE;
    }

    // 位置は作成後に設定
    glfwSetWindowPos(win, WindowPositionX, WindowPositionY);

    glfwMakeContextCurrent(win);
    glfwSwapInterval(1); // vsync

    if(!gladLoadGL()){
        std::fprintf(stderr, "Failed to load OpenGL via GLAD\n");
        return EXIT_FAILURE;
    }

    glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);
    glViewport(0, 0, WindowWidth, WindowHeight);

    // 深度テストON（旧 initialize() の相当）
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.f, 0.f, 0.f, 1.f);

    // ====== 立方体の頂点・色・インデックス（旧 draw() のデータを整理） ======
    // 位置(x,y,z) + 色(r,g,b,a)
    struct Vertex { float x,y,z,r,g,b,a; };

    const std::array<Vertex, 24> vertices = {{
        // A面
        {-1,-1, 1, 1,0,0,1}, { 1,-1, 1, 1,1,0,1}, { 1, 1, 1, 1,1,1,1}, {-1, 1, 1, 1,0,1,1},
        // B面
        {-1,-1,-1, 0,0,0,1}, {-1, 1,-1, 0,0,1,1}, { 1, 1,-1, 0,1,1,1}, { 1,-1,-1, 0,1,0,1},
        // C面
        {-1, 1,-1, 0,0,1,1}, {-1, 1, 1, 1,0,1,1}, { 1, 1, 1, 1,1,1,1}, { 1, 1,-1, 0,1,1,1},
        // D面
        {-1,-1,-1, 0,0,0,1}, { 1,-1,-1, 0,1,0,1}, { 1,-1, 1, 1,1,0,1}, {-1,-1, 1, 1,0,0,1},
        // E面
        { 1,-1,-1, 0,1,0,1}, { 1, 1,-1, 0,1,1,1}, { 1, 1, 1, 1,1,1,1}, { 1,-1, 1, 1,1,0,1},
        // F面
        {-1,-1,-1, 0,0,0,1}, {-1,-1, 1, 1,0,0,1}, {-1, 1, 1, 1,0,1,1}, {-1, 1,-1, 0,0,1,1}
    }};

    const std::array<unsigned, 36> indices = {{
        0,1,2, 0,2,3,    // A
        4,5,6, 4,6,7,    // B
        8,9,10, 8,10,11, // C
        12,13,14, 12,14,15, // D
        16,17,18, 16,18,19, // E
        20,21,22, 20,22,23  // F
    }};

    // ====== VAO/VBO/EBO ======
    GLuint vao=0, vbo=0, ebo=0;
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices.data(), GL_STATIC_DRAW);

    // layout(location=0) -> position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);
    // layout(location=1) -> color
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    // ====== シェーダプログラム ======
    GLuint prog = link_program(compile_shader(GL_VERTEX_SHADER, kVS),
                               compile_shader(GL_FRAGMENT_SHADER, kFS));
    GLint locMVP = glGetUniformLocation(prog, "uMVP");

    // ====== メインループ（旧 idle()/display() 相当） ======
    double startTime = glfwGetTime();

    while(!glfwWindowShouldClose(win)){
        glfwPollEvents();

        int fbw, fbh;
        glfwGetFramebufferSize(win, &fbw, &fbh);
        glViewport(0, 0, fbw, fbh);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // 回転角
        double t = glfwGetTime() - startTime;
        float angle = static_cast<float>(t * 60.0); // deg/sec

        // ====== 行列（旧 gluPerspective + gluLookAt の代替：GLM） ======
        float aspect = (fbh==0) ? 1.0f : static_cast<float>(fbw)/static_cast<float>(fbh);

        glm::mat4 proj = glm::perspective(glm::radians(30.0f), aspect, 0.1f, 1000.0f);
        glm::mat4 view = glm::lookAt(
            glm::vec3(5.0f, 5.0f, 5.0f),  // eye
            glm::vec3(0.0f, 0.0f, 0.0f),  // center
            glm::vec3(0.0f, 0.0f, 1.0f)   // up
        );
        glm::mat4 model = glm::rotate(glm::mat4(1.0f), glm::radians(angle),
                                      glm::vec3(0.0f, 0.0f, 1.0f));

        glm::mat4 mvp = proj * view * model;

        glUseProgram(prog);
        glUniformMatrix4fv(locMVP, 1, GL_FALSE, glm::value_ptr(mvp));

        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        glfwSwapBuffers(win);
    }

    // 後片付け
    glDeleteProgram(prog);
    glDeleteBuffers(1, &ebo);
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    glfwDestroyWindow(win);
    glfwTerminate();
    return EXIT_SUCCESS;
}
