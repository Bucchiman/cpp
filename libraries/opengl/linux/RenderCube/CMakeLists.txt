# CMakeLists.txt
cmake_minimum_required(VERSION 3.16)
project(ModernOpenGLCube LANGUAGES C CXX)

# ===== Build setup =====
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# -O2 など（お好みで）
if(MSVC)
  add_compile_options(/W4)
else()
  add_compile_options(-Wall -Wextra -Wshadow -Wconversion)
endif()

# ===== GLAD path (override with -DGLAD_DIR=...) =====
if(NOT DEFINED GLAD_DIR)
  if(DEFINED ENV{HOME})
    set(GLAD_DIR "$ENV{HOME}/source/glad")
  else()
    set(GLAD_DIR "${CMAKE_SOURCE_DIR}/third_party/glad") # フォールバック
  endif()
endif()

# ===== Sources =====
set(SRCS
  ${CMAKE_SOURCE_DIR}/main.cpp
  ${GLAD_DIR}/src/glad.c
)

add_executable(main ${SRCS})

# ===== Include paths =====
target_include_directories(main PRIVATE
  ${GLAD_DIR}/include
)

# ===== OpenGL =====
find_package(OpenGL REQUIRED)
target_link_libraries(main PRIVATE OpenGL::GL)

# ===== GLFW (pkg-config 優先) =====
find_package(PkgConfig QUIET)
if(PkgConfig_FOUND)
  pkg_check_modules(GLFW3 QUIET glfw3)
endif()

if(GLFW3_FOUND)
  target_include_directories(main PRIVATE ${GLFW3_INCLUDE_DIRS})
  target_link_libraries(main PRIVATE ${GLFW3_LINK_LIBRARIES})
else()
  # pkg-config が無い/見つからない場合のフォールバック
  # Ubuntuのlibglfw3-dev だと find_package(glfw3 CONFIG) が効くことが多いです
  find_package(glfw3 REQUIRED)
  # ターゲット名は環境により "glfw" / "glfw3::glfw" など異なる可能性があるので両対応
  if(TARGET glfw)
    target_link_libraries(main PRIVATE glfw)
  elseif(TARGET glfw3::glfw)
    target_link_libraries(main PRIVATE glfw3::glfw)
  else()
    message(FATAL_ERROR "glfw target was not found even though glfw3 was required.")
  endif()
endif()

# ===== POSIX 環境向けの追加ライブラリ =====
# glad が dlopen を使う場合があるため Linux では -ldl を付与
if(UNIX AND NOT APPLE)
  target_link_libraries(main PRIVATE dl)
endif()

# ===== macOS の場合（参考：通常は GLFW が内部で解決） =====
if(APPLE)
  # GLFW がフレームワークを引き回してくれることが多いので基本は不要
  # target_link_libraries(main PRIVATE "-framework Cocoa" "-framework IOKit" "-framework CoreVideo")
endif()

# ===== Nice-to-have: 出力ディレクトリ整備 =====
set_target_properties(main PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)
