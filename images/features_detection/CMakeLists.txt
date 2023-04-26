#
# FileName:     CMakeLists
# Author:       8ucchiman
# CreatedDate:  2023-04-25 11:15:36
# LastModified: 2023-03-29 18:30:18 +0900
# Reference:    https://qiita.com/shohirose/items/45fb49c6b429e8b204ac
#               https://cmake.org/cmake/help/git-master/prop_gbl/CMAKE_CXX_KNOWN_FEATURES.html#prop_gbl:CMAKE_CXX_KNOWN_FEATURES
# Description:  ---
#



cmake_minimum_required(VERSION 2.8)
project(FeatureDetect)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(main main.cpp)
target_link_libraries(main ${OpenCV_LIBS})



## cmake -S . -B build -DBUILD_SHARED_LIBS=ON    # 共有ライブラリ指定
#
#####################
## 静的ライブラリ作成
#####################
#cmake_minimum_required(VERSION 3.13)
#project(test_cmake CXX)     # test_cmakeプロジェクトをc++で作成
## hello.cppとgood_morning.cppをコンパイルして静的ライブラリlibgreetings.aを作成
#add_library(greetings STATIC hello.cpp good_morning.cpp)
## a.outという実行ファイルをmain.cppから作成
#add_executable(a.out main.cpp)
## a.outを作成する際にlibgreetings.aをリンク
#target_link_libraries(a.out greetings)
#
#
#####################
## 動的ライブラリ作成
#####################
#cmake_minimum_required(VERSION 3.13)
#project(test_cmake CXX)
## hello.cppとgood_morning.cppをコンパイルして共有ライブラリlibgreetings.soを作成
#add_library(greetings SHARED hello.cpp good_morning.cpp)
#add_executable(a.out main.cpp)
## a.outを作成する際にlibgreetings.soをリンク
#target_link_libraries(a.out greetings)
#
#
#####################
## 各ライブラリ毎に静的、動的を指定する
## cmake -S . -B build -DGREETINGS_BUILD_SHARED_LIBS=ON
#####################
## GREETINGS_BUILD_SHARED_LIBSというオプションを作成。デフォルトをOFFに設定。
#option(GREETINGS_BUILD_SHARED_LIBS "build greetings as a shared library" OFF)
#
#if (GREETINGS_BUILD_SHARED_LIBS)
#  add_library(greetings SHARED hello.cpp good_morning.cpp)
#else()
#  add_library(greetings STATIC hello.cpp good_morning.cpp)
#endif()
#
#####################
## サブディレクトリ登録
#####################
#add_subdirectory(src)
#add_subdirectory(test)
#
#####################
## コンパイルオプション設定
#####################
## 最適化・警告などのオプション
#target_compile_options(a.out PUBLIC -O2 -Wall)
#
## C++の標準規格の指定
#target_compile_features(a.out PUBLIC cxx_std_17)
#
## マクロ
#target_compile_definitions(a.out PUBLIC MY_ORIGINAL_MACRO_CONST=1)
#
#
#####################
## ビルドタイプの指定
#####################
## $ cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
## $ cmake --build build
#
#####################
## ジェネレーター式
## コンパイラによってコンパイルオプションが異なる。
## e.g. gcc,           -Wall
##      visual studio, /W4
#####################
#cmake_minimum_required(VERSION 3.13)
#project(cmake_example CXX)
#
#add_executable(a.out main.cpp)
#target_compile_options(a.out PUBLIC
#  # ビルドタイプによって変更する
#  $<$<CONFIG:Release>: ...>          # Release
#  $<$<CONFIG:Debug>: ...>            # Debug
#  $<$<CONFIG:RelWithDebgInfo>: ...>  # RelWithDebInfo
#
#  # OSに応じて変更する
#  $<$<PLATFORM_ID:Darwin>: ...>   # Mac
#  $<$<PLATFORM_ID:Linux>: ...>    # Linux
#  $<$<PLATFORM_ID:Windows>: ...>  # Windows
#
#  # コンパイラによって変更する
#  $<$<CXX_COMPILER_ID:MSVC>: ...>      # MSVC
#  $<$<CXX_COMPILER_ID:GNU>: ...>       # GCC
#  $<$<CXX_COMPILER_ID:Clang>: ...>     # LLVM Clang
#  $<$<CXX_COMPILER_ID:Intel>: ...>     # Intel classic
#  $<$<CXX_COMPILER_ID:IntelLLVM>: ...> # Intel one-API
#  )
#target_compile_definitions(a.out PUBLIC
#  $<$<NOT:$<CONFIG:Debug>>: ...>     # Debugビルド以外
#  )
#
#
#####################
## ライブラリのリンク
#####################
## $ g++ -o target main.cpp -lhoge
##
## -> 
#target_link_libraries(target PUBLIC -lhoge)
#
