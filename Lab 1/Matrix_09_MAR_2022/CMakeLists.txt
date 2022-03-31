cmake_minimum_required(VERSION 3.21)
project(Matrix_09_MAR_2022)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(main
        main.cpp
        mat_test.cpp
        mat_test.h
        matrix.cpp
        matrix.h)
