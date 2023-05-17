// SampleGL.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
// Referece> https://codelabo.com/posts/20200228150223
//

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main()
{
    std::cout << "Hello World!\n";
    // GLFW初期化
    if (glfwInit() == GL_FALSE) 
    {
        return -1;
    }

    // ウィンドウ生成
    GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL Simple", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // バージョン2.1指定
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);

    // GLEW初期化
    if (glewInit() != GLEW_OK) 
    {
        return -1;
    }

    // フレームループ
    while (glfwWindowShouldClose(window) == GL_FALSE) 
    {
        // バッファのクリア
        glClearColor(0.2f, 0.2f, 0.2f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // 色指定
        glColor4f(1.0, 0.0, 0.0, 1.0);

        // 3つの頂点座標をGPUに転送
        glBegin(GL_TRIANGLES);
        glVertex2f(   0,  0.5);
        glVertex2f(-0.5, -0.5);
        glVertex2f( 0.5, -0.5);
        glEnd();

        // ダブルバッファのスワップ
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // GLFWの終了処理
    glfwTerminate();

    return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
