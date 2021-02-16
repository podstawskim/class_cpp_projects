cmake_minimum_required(VERSION 3.16)
project(externals)

set(BUILD_GMOCK OFF CACHE BOOL "Suppressing gmock build" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "Suppressing gtest install" FORCE)
add_subdirectory(googletest)

set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark tests" FORCE)
add_subdirectory(benchmark)
