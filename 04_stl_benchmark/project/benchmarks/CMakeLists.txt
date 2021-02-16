cmake_minimum_required(VERSION 3.16)
project(benchmarks)

set(BENCHMARKS_HEADERS
        include/BenchIncludes.h)

set(BENCHMARKS_SOURCES
        src/DummyBench.cpp src/ExampleBench.cpp src/PauseAndResumeBench.cpp
        src/SmallBench.cpp src/MediumBench.cpp src/LargeBench.cpp src/SmallBenchmark.cpp src/MediumBenchmark.cpp src/LargeBenchmark.cpp)

add_executable(benchmarks ${BENCHMARKS_HEADERS} ${BENCHMARKS_SOURCES})
target_include_directories(benchmarks PUBLIC include)
target_link_libraries(benchmarks PRIVATE utils)

target_link_libraries(benchmarks PRIVATE benchmark benchmark_main pthread)
