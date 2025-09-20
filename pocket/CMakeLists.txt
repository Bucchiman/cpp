cmake_minimum_required(VERSION 2.8.3)
project(Bmods CXX)
set(SOURCE_FILE Bmods.cpp)

# OpenCVのビルド環境の設定ファイルを読み込む
find_package(OpenCV REQUIRED)

# OpenCV関係のインクルードディレクトリのパスを設定
include_directories(
    ${OpenCV_INCLUDE_DIRS}
)

add_library(Bmods SHARED Bmods.cpp)

# 実行ファイル名を設定
# add_executable(Bmods
#     ${SOURCE_FILE}
# )
# 
# # リンクするライブラリを読み込む
# target_link_libraries(Bmods
#     ${OpenCV_LIBRARIES} Bdev
# )
