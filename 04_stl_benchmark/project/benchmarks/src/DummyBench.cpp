#include "Dummy.h"
#include "BenchIncludes.h"

static void Dummy_Integrate(State& state) {

    for (auto _ : state) {

        Dummy dummy{0, state.range(0)};
        auto integral = dummy.integrate();

       // DoNotOptimize(integral);
    }

    state.SetComplexityN(state.range(0));
}

BENCHMARK(Dummy_Integrate)->RangeMultiplier(2)->Range(1u << 5u, 1u << 18u)->Complexity();
