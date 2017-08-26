cmake_minimum_required (VERSION 2.6)
project (RPGProject)

set(CMAKE_CXX_COMPILER, clang++)

file(GLOB PROJECT_SRC
    "${PROJECT_SOURCE_DIR}/*.h"
    "${PROJECT_SOURCE_DIR}/*.cpp"
)

add_executable(RPGProject "${PROJECT_SRC}")

TARGET_LINK_LIBRARIES(RPGProject SDL2 SDL2_ttf SDL2_image)

if (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/include/SDL2 -D_REENTRANT -g -Wall -Werror -std=c++14")
endif(UNIX)

