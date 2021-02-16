cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
project(project)

add_library(utils
        include/Point.h
        include/SpaceImpl.h
        include/TimeImpl.h
        include/Universe.h
        include/ObserverImpl.h
        src/SpaceImpl.cpp
        src/TimeImpl.cpp
        src/ObserverImpl.cpp
        src/Universe.cpp)

target_include_directories(utils PUBLIC include)

add_executable(runner src/main.cpp include/Space.h include/Time_.h include/Observer.h)
target_link_libraries(runner PRIVATE utils)

add_subdirectory(tests)
