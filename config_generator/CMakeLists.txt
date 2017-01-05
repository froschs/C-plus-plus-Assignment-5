cmake_minimum_required(VERSION 3.3)
project(Assignment5Generator)

include_directories("C:\\Users\\Seth\\Desktop\\WCCC\\CPT 180 - C++ Programming\\Assignment5\\config_reader_lib")
link_directories("C:\\Users\\Seth\\Desktop\\WCCC\\CPT 180 - C++ Programming\\Assignment5\\config_reader_lib")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp generator.h)
add_executable(Assignment5Generator ${SOURCE_FILES} generator.h)
target_link_libraries(Assignment5Generator Assignment5)