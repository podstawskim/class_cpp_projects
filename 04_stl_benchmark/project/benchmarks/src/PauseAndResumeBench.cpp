#include "BenchIncludes.h"

void pauseAndResume(State& state) {

    for (auto _ : state) {
        // That is very slow and should be avoided
        // That overhead will be always added and can hide what you are trying to measure
        state.PauseTiming();
        state.ResumeTiming();
    }
}

// On my machine it takes ~330ns
BENCHMARK(pauseAndResume);


void somethingInPauseAndResume(State& state) {

    auto N = state.range(0);

    for (auto _ : state) {

        // Overhead will be also added
        state.PauseTiming();

        // This linearly growing thing will not be counted into resulting time
        // It won't be also taken into account while checking whether benchmark should be stopped
        // If this time grows with N than overall execution will also grow - but library will not see that!

        for (int i = 0; i < N; ++i) {
            auto something = i+1;
            DoNotOptimize(something);
        }

        state.ResumeTiming();
    }

    state.SetComplexityN(N);
}

// This benchmark will take very long time to finish - result should be 0(1)
BENCHMARK(somethingInPauseAndResume)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();

void linearComplexityAndSomethingInPauseAndResume(State& state) {

    auto N = state.range(0);

    for (auto _ : state) {

        // Overhead will be also added
        state.PauseTiming();

        // This linearly growing thing will be not counted into resulting time
        for (int i = 0; i < N; ++i) {
            auto something = i+1;
            DoNotOptimize(something);
        }

        state.ResumeTiming();


        // This linearly growing thing will be measured
        for (int i = 0; i < N; ++i) {
            auto something = i+1;
            DoNotOptimize(something);
        }
    }

    state.SetComplexityN(N);
}

// Linear complexity will be probably lost here - that was case for range to 2^10 - I've got 0(1)
// That's why I've increased range from 2^10 to 2^15 and complexity was correct O(N)
// Conclusion - measured time must be much larger than Pause/Resume overhead
BENCHMARK(linearComplexityAndSomethingInPauseAndResume)->RangeMultiplier(2)->Range(1u, 1u << 15u)->Complexity();
