#include "Medium.h"
#include "BenchIncludes.h"

static void MediumLessThanOperator(State &state) {
    Medium a{};
    Medium b{};

    a.randomize();
    b.randomize();

    for (auto _: state) {
        auto i = a < b;
        DoNotOptimize(i);
    }
}

BENCHMARK(MediumLessThanOperator);

static void MediumEqualOperator(State &state) {
    Medium a{};
    Medium b{};

    a.randomize();
    b.randomize();

    for (auto _: state) {
        auto i = a == b;
        DoNotOptimize(i);
    }

}

BENCHMARK(MediumEqualOperator);

static void MediumHash(State& state) {
    Medium a{};
    a.randomize();

    for(auto _ : state) {
        auto i = std::hash<Medium>{}(a);
        DoNotOptimize(i);
    }

}
BENCHMARK(MediumHash);