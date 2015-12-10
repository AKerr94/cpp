cmake_minimum_required(VERSION 3.3)
project(People)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        main.cpp
        Person.cpp
        Person.h
        Student.cpp
        Student.h
        Score.cpp
        Score.h)

add_executable(People ${SOURCE_FILES})
