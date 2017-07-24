cmake_minimum_required(VERSION 3.8)
project(kinect_linux)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(kinect_linux ${SOURCE_FILES})