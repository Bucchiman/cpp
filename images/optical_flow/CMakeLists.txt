cmake_minimum_required(VERSION 2.8.3)
project(step1)
set(SOURCE_FILE lucas_kanade.cpp)

# OpenCVのビルド環境の設定ファイルを読み込む
find_package(OpenCV REQUIRED)

# OpenCV関係のインクルードディレクトリのパスを設定
include_directories(
    ${OpenCV_INCLUDE_DIRS}
)

# 実行ファイル名を設定
add_executable(lucas_kanade
    ${SOURCE_FILE}
)

# リンクするライブラリを読み込む
target_link_libraries(lucas_kanade
    ${OpenCV_LIBRARIES}
)
