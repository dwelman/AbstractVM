cmake_minimum_required(VERSION 3.7)
project(avm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES    targsrc/main.cpp
                    targsrc/Util.cpp
                    targsrc/Parser.cpp)

set(HEADER_FILES    includes/Util.hpp
                    includes/Parser.hpp)

include_directories(avm includes)

add_executable(avm ${SOURCE_FILES} ${HEADER_FILES})