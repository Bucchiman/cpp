#
# FileName:     CMakeLists
# Author:       8ucchiman
# CreatedDate:  2023-12-09 16:16:21
# LastModified: 2023-12-09 18:08:11
# Reference:    https://qiita.com/shohirose/items/45fb49c6b429e8b204ac
#               https://cmake.org/cmake/help/git-master/prop_gbl/CMAKE_CXX_KNOWN_FEATURES.html#prop_gbl:CMAKE_CXX_KNOWN_FEATURES
# Description:  ---
#


cmake_minimum_required(VERSION 2.8)
project( DisplayImage )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( DisplayImage DisplayImage.cpp )
target_link_libraries( DisplayImage ${OpenCV_LIBS} )
