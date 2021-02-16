#include "BenchIncludes.h"
#include <set>
#include <cmath>

void linearComplexity(State& state) {

    auto N = state.range(0);

    for (auto _ : state) {

        for (int i = 0; i < N; ++i) {
            auto something = i+1;

            // Only for Release mode - without that optimizer will remove our code
            DoNotOptimize(something);
        }
    }

    state.SetComplexityN(N);
}

BENCHMARK(linearComplexity)->RangeMultiplier(2)->Range(1u, 1024u)->Complexity();

// This kind of benchmarks can be used for every method that does not modify container (opposed to e.g.: insert or erase).
// Before entering 'for' loop we need to create collection and fill it with some data
// In 'for' loop we can simply call the method we want
// One more time - this will work ONLY FOR METHODS THAT DO NOT MODIFY CONTAINER

void vectorSize(State& state) {

    // Two variables are added to avoid compiler warnings
    auto N = state.range(0);
    auto size = (std::size_t)N;

    // Vector can be defined outside loop because size() function does not modify it
    std::vector<float> vector(size);

    for (auto _ : state) {

        // Only for Release mode - prevent optimization that will remove function call
        // We can always do that when we have object or method that returns something
        DoNotOptimize(vector.size());
    }

    state.SetComplexityN(N);
 }

// You should adjust range to fully utilize available RAM

BENCHMARK(vectorSize)->RangeMultiplier(2)->Range(1u, 1024u)->Complexity();

void logarithmicComplexity(State& state) {

    auto N = state.range(0);

    // In this benchmark we will be testing something that has logarithmic complexity
    // One example might be inserting into std::set (it is really a binary tree underneath)

    // First step is to create set with some random integers
    std::set<int> set;
    for (int i = 0; i < N; ++i) {
        set.insert(rand());
    }

    for (auto _ : state) {

        // Data in each iteration should be random - if it is not we can get other complexity than expected
        // Function to generate random numbers is 0(1) - it should have small impact on overall performance
        auto number = rand();

        // Here we guess that insert and erase have the same complexity
        // If that's the case then O(2*logN) is the same as O(logN)

        set.insert(number);
        auto result = set.erase(number);

        // Just to keep all around in Release mode
        // Last function call to erase() returns something that depends on insert()
        // Insert depends on number generated earlier
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);
}

BENCHMARK(logarithmicComplexity)->RangeMultiplier(2)->Range(1u << 8u, 1u << 16u)->Complexity();

void randBenchmark(State& state) {

    for (auto _ : state) {

        auto number = rand();
        DoNotOptimize(number);
    }
}

BENCHMARK(randBenchmark);

// Below example shows how benchmark can be implemented in incremental way with baselines
// First we measure how much time it takes to create vector of given size
// in second benchmark we will measure creation and push_back() together

void vectorCreate(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::vector<float> vector(size);

        // Only for Release mode - prevent optimization that will remove vector created above
        // We can always do that when we have object or method return something
        DoNotOptimize(vector);
    }

    state.SetComplexityN(N);
}

BENCHMARK(vectorCreate)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void vectorCreateAndPushBack(State& state) {

    auto N = state.range(0);
    auto size = (std::size_t)N;

    for (auto _ : state) {

        std::vector<float> vector(size);

        // Only for Release mode - keep around data inside vector where new element will be added
        DoNotOptimize(vector.data());

        vector.push_back(10);

        // Only for Release mode - read memory to make sure that push_back() is not optimized away
        // This will also make sure that any pending memory operations are executed
        ClobberMemory();

        // DoNotOptimize(x) and ClobberMemory() are all that is needed to prevent optimization
        // Google benchmark does not provide other methods because we should be able to everything with those two
        // See https://youtu.be/nXaxk27zwlk?t=2441 if you want to know what happens here :)
    }

    state.SetComplexityN(N);
}

BENCHMARK(vectorCreateAndPushBack)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();
