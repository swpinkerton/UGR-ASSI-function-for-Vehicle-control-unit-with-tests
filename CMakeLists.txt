cmake_minimum_required(VERSION 3.5)
project(UGRtest)

set(CMAKE_CXX_STANDARD 17)


include_directories(Function_lib)
add_subdirectory(Function_lib)

add_executable(UGRtest main.cpp)
add_subdirectory(Google_Tests)