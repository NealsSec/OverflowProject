cmake_minimum_required(VERSION 3.0)
project(Overflow C)

include_directories(include)

file(GLOB SOURCES "src/*.c")

add_executable(overflow ${SOURCES})