cmake_minimum_required(VERSION 3.26)
project(simple_time C)

set(CMAKE_C_STANDARD 11)

add_executable(simple_time main.c
        simple_time_lib.h
        simple_time_lib.c
)
