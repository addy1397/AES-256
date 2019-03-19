cmake_minimum_required(VERSION 3.13)
project(New_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(New_Project main.cpp)


