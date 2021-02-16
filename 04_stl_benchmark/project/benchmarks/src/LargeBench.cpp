#include "Large.h"
#include "BenchIncludes.h"

static void LargeLessThanOperator(State& state){
    Large a{};
    Large b{};

    a.randomize();
    b.randomize();

    for(auto _ : state) {
        auto i = a < b;
        DoNotOptimize(i);
    }
}

BENCHMARK(LargeLessThanOperator);

static void LargeEqualOperator(State& state){
    Large a{};
    Large b{};

    a.randomize();
    b.randomize();

    for(auto _ : state) {
        auto i = a == b;
        DoNotOptimize(i);
    }
}
BENCHMARK(LargeEqualOperator);


static void LargeHash(State& state) {
    Large a{};
    a.randomize();

    for(auto _ : state) {
        auto i = std::hash<Large>{}(a);
        DoNotOptimize(i);
    }

}
BENCHMARK(LargeHash);



