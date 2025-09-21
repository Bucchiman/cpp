#
# FileName:     CMakeLists
# Author:       8ucchiman
# CreatedDate:  2025-09-14 22:24:22
# LastModified: 2023-12-13 12:14:04
# Command:      cmake -S . -B build -DBUILD_SHARED_LIBS=ON    # 共有ライブラリ指定
# Reference:    https://qiita.com/shohirose/items/45fb49c6b429e8b204ac
#               https://cmake.org/cmake/help/git-master/prop_gbl/CMAKE_CXX_KNOWN_FEATURES.html#prop_gbl:CMAKE_CXX_KNOWN_FEATURES
# Description:  ---
#


cmake_minimum_required(VERSION 3.13)
project(8ucchiman_project CXX)   # 8ucchiman_projectをc++で作成

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SRCS main.cpp shader.cpp texture.cpp)

add_executable(main
    ${SRCS})

find_package(OpenGL REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)
pkg_check_modules(GLEW REQUIRED glew)

target_include_directories(main PRIVATE
    ${GLFW_INCLUDE_DIRS}
    ${GLEW_INCLUDE_DIRS}
)

target_link_libraries(main PRIVATE
    ${GLFW_LIBRARIES}
    ${GLEW_LIBRARIES}
    OpenGL::GL
)

target_link_directories(main PRIVATE
    ${GLFW_LIBRARY_DIRS}
    ${GLEW_LIBRARY_DIRS}
)
