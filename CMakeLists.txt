cmake_minimum_required(VERSION 3.12)
project(Test C)

set(CMAKE_C_STANDARD 11)

include_directories( ${MY_SOURCE_DIR}/src )

add_executable(Test main.c)