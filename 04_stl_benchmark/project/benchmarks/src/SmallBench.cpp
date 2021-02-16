#include "Small.h"
#include "BenchIncludes.h"

static void LessThanOperator(State& state) {
    auto N = state.range(0);

    Small a{};
    Small b{};

    a.randomize();
    b.randomize();

    for(auto _ : state) {
        auto i = a<b;
        DoNotOptimize(i);
    }
    state.SetComplexityN(N);
}

BENCHMARK(LessThanOperator);

static void EqualOperator(State& state) {
    Small a{};
    Small b{};

    a.randomize();
    b.randomize();

    for(auto _:state)
    {
        auto i = a==b;
        DoNotOptimize(i);
    }
}

BENCHMARK(EqualOperator);

static void Hash(State& state) {
    Small a{};
    a.randomize();

    for(auto _ : state) {
        auto i = std::hash<Small>{}(a);
        DoNotOptimize(i);
    }
}
BENCHMARK(Hash);