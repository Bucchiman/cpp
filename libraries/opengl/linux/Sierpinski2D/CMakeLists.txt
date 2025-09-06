#
# FileName:     CMakeLists
# Author:       8ucchiman
# CreatedDate:  2025-09-06 17:35:31
# LastModified: 2023-12-13 12:14:04
# Command:      cmake -S . -B build -DBUILD_SHARED_LIBS=ON    # 共有ライブラリ指定
# Reference:    https://qiita.com/shohirose/items/45fb49c6b429e8b204ac
#               https://cmake.org/cmake/help/git-master/prop_gbl/CMAKE_CXX_KNOWN_FEATURES.html#prop_gbl:CMAKE_CXX_KNOWN_FEATURES
# Description:  ---
# cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -S . -B build
#


cmake_minimum_required(VERSION 3.13)
project(8ucchiman_project CXX)   # 8ucchiman_projectをc++で作成

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# load packages
find_package(OpenCV REQUIRED)

# set path of include directories
include_directories()

if(NOT DEFINED GLAD_DIR)
  if(DEFINED ENV{HOME})
    set(GLAD_DIR "$ENV{HOME}/source/glad")
  else()
    set(GLAD_DIR "${CMAKE_SOURCE_DIR}/third_party/glad") # フォールバック
  endif()
endif()

set(SRCS main.cpp ${GLAD_DIR}/src/glad.c)

# set executable
add_executable(main
    ${SRCS})

target_include_directories(
    main PRIVATE
    ${GLAD_DIR}/include
)

