cmake_minimum_required(VERSION 3.10.2)
project(AES-256)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(AES-256 main.cpp)


