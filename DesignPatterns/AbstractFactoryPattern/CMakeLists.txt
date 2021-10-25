cmake_minimum_required(VERSION 3.1)
project (testing)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_COLOR_MAKEFILE   ON)
set(CMAKE_CXX_FLAGS "-Wall")

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/*.cpp")
add_executable(${PROJECT_NAME} main.cpp ${SOURCES})