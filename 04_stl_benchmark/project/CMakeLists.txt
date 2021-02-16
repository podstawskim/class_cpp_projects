cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
project(stl_benchmark)

set(HEADERS
        include/Dummy.h include/Small.h
        include/Medium.h include/Large.h)

set(SOURCES src/Dummy.cpp)

add_library(utils ${HEADERS} ${SOURCES})
target_include_directories(utils PUBLIC include)

add_executable(runner src/main.cpp)
target_link_libraries(runner PRIVATE utils)

add_subdirectory(externals)

add_subdirectory(tests)
add_subdirectory(benchmarks)
