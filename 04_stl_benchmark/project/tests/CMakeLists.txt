cmake_minimum_required(VERSION 3.16)
project(tests)

set(TESTS_HEADERS
        include/TestIncludes.h)

set(TESTS_SOURCES
        src/DummyTest.cpp src/SmallTest.cpp
        src/MediumTest.cpp src/LargeTest.cpp)

add_executable(tests ${TESTS_HEADERS} ${TESTS_SOURCES})
target_include_directories(tests PRIVATE include)
target_link_libraries(tests PRIVATE utils)

target_link_libraries(tests PRIVATE gtest gtest_main pthread)
