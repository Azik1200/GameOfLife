cmake_minimum_required(VERSION 3.22)
project(GameOfLife C)

set(CMAKE_C_STANDARD 23)

add_executable(GameOfLife main.c board.c board.h)
