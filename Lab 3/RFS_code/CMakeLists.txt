cmake_minimum_required(VERSION 3.21)
project(RFS_code)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(include)

add_executable(RFS_code
        include/School.h
        src/School.cpp
        main.cpp
        record.cpp
        record.h
        RFS.cpp
        RFS.h
        School.cpp
        School.h
        conio.h
        Student.cpp
        Student.h)
