cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(project)

add_library(utils include/Calculator.h src/Calculator.cpp)

target_include_directories(utils PUBLIC include)

add_executable(runner src/main.cpp)
target_link_libraries(runner PRIVATE utils)

add_subdirectory(tests)
