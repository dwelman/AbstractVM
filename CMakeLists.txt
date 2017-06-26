cmake_minimum_required(VERSION 3.7)
project(avm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES targsrc/main.cpp)

add_executable(avm ${SOURCE_FILES})