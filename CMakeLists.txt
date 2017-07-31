cmake_minimum_required(VERSION 3.8)
project(kinect_linux)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp pk_kinect.cpp pk_kinect.h)
add_executable(kinect_linux ${SOURCE_FILES})

find_package(OpenCV REQUIRED)
target_link_libraries(kinect_linux ${OpenCV_LIBS})

find_package(freenect2 REQUIRED)
target_link_libraries(kinect_linux ${freenect2_LIBRARIES})
