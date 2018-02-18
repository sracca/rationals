cmake_minimum_required(VERSION 3.6)
project(PA5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES PA5.cpp Rational.cpp Rational.h makefile)
add_executable(PA5 ${SOURCE_FILES})