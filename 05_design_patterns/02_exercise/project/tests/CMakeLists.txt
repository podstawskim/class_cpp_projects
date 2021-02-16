cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
add_executable(tests
        src/CalculatorTest.cpp src/ObserverTest.cpp)


target_link_libraries(tests PRIVATE utils)

set(GTEST ../../googletest)

target_include_directories(tests PRIVATE ${GTEST}/googletest/include)
target_link_directories(tests PRIVATE ${GTEST}/build/lib)

target_link_libraries(tests PRIVATE gtest gtest_main pthread)
