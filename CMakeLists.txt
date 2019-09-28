cmake_minimum_required(VERSION 3.15)
project(Overflow)

include_directories(include)

file(GLOB SOURCES "src/*.c")

add_executable(overflow ${SOURCES})