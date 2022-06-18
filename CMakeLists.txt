cmake_minimum_required(VERSION 3.22)
project(GameOfLife C)

set(CMAKE_C_STANDARD 23)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(GameOfLife main.c board.c board.h)
target_link_libraries(GameOfLife ${SDL2_LIBRARIES})

