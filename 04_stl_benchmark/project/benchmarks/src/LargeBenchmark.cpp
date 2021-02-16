//
// Created by Michał Podstawski on 08/12/2020.
//


#include "BenchIncludes.h"
#include "Large.h"
#include <vector>
#include <unordered_map>
#include <map>


void large_vectorAt(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Large> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector.at(0));
    }

    state.SetComplexityN(N);
}

BENCHMARK(large_vectorAt)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_vectorOperator(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Large> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector[0]);
    }

    state.SetComplexityN(N);
}

BENCHMARK(large_vectorOperator)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_vectorFront(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Large> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector.front());
    }

    state.SetComplexityN(N);
}

BENCHMARK(large_vectorFront)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_vectorBack(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Large> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector.back());
    }

    state.SetComplexityN(N);
}

BENCHMARK(large_vectorBack)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_vectorData(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Large> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector.data());
    }

    state.SetComplexityN(N);
}

BENCHMARK(large_vectorData)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_vectorEmpty(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Large> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector.empty());
    }

    state.SetComplexityN(N);
}

BENCHMARK(large_vectorEmpty)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_vector_size(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Large> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector.size());
    }

    state.SetComplexityN(N);
}

BENCHMARK(large_vector_size)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_vectorMaxSize(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Large> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector.max_size());
    }

    state.SetComplexityN(N);
}

BENCHMARK(large_vectorMaxSize)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_vectorReserve(State &state) { //complexity: at most linear
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Large> vector(size);

    for (auto _ : state) {
        for (int i = 0; i < size; i++)
            vector.reserve(i);
    }
    state.SetComplexityN(N);

}

BENCHMARK(large_vectorReserve)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_vectorCapacity(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Large> vector(size);

    for (auto _ : state) {
        DoNotOptimize(vector.capacity());
    }
    state.SetComplexityN(N);

}

BENCHMARK(large_vectorCapacity)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_vectorShrinkToFit(State &state) { //complexity: at most linear
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Large> vector(size);

    for (auto _ : state) {

        for (int i = 0; i < size; i++)
            vector.shrink_to_fit();
    }
    state.SetComplexityN(N);
}

BENCHMARK(large_vectorShrinkToFit)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_vector_create(State &state) { //complexity: linear

    auto N = state.range(0);
    auto size = (std::size_t) N;

    for (auto _ : state) {

        std::vector<Large> vector(size);

        DoNotOptimize(vector);
    }

    state.SetComplexityN(N);
}

BENCHMARK(large_vector_create)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_vectorCreateAndClear(State &state) { //complexity: linear in a size of container
    auto N = state.range(0);
    auto size = (std::size_t) N;

    for (auto _ : state) {
        std::vector<Large> vector(size);
        DoNotOptimize(vector.data());

        vector.clear();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(large_vectorCreateAndClear)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_vectorCreateAndInsert(State &state) { //complexity: linear
    auto N = state.range(0);
    auto size = (std::size_t) N;

    Large a{};
    a.randomize();

    for (auto _ : state) {
        std::vector<Large> vector(size);
        DoNotOptimize(vector.data());

        vector.insert(vector.begin(), a);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(large_vectorCreateAndInsert)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_vectorCreateAndErase(State &state) { //complexity: linear
    auto N = state.range(0);
    auto size = (std::size_t) N;

    for (auto _ : state) {
        std::vector<Large> vector(size);
        DoNotOptimize(vector.data());

        vector.erase(vector.begin());
        ClobberMemory();
    }

    state.SetComplexityN(N);

}

BENCHMARK(large_vectorCreateAndErase)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_vectorCreateAndPush_Back(State &state) { //complexity: linear

    auto N = state.range(0);
    auto size = (std::size_t) N;

    for (auto _ : state) {

        std::vector<Large> vector(size);
        DoNotOptimize(vector.data());

        Large a{};
        a.randomize();

        vector.push_back(a);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(large_vectorCreateAndPush_Back)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_vectorCreateAndPopBack(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    for (auto _ : state) {

        std::vector<Large> vector(size);
        DoNotOptimize(vector.data());

        vector.pop_back();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(large_vectorCreateAndPopBack)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_vectorCreateAndResize(State &state) {
    auto N = state.range(0);
    auto size = (std::size_t) N;

    for (auto _ : state) {

        std::vector<Large> vector(size);
        DoNotOptimize(vector.data());

        vector.resize(10);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(large_vectorCreateAndResize)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_vectorCreateAndSwap(State &state) {
    auto N = state.range(0);
    auto size = (std::size_t) N;

    for (auto _ : state) {
        std::vector<Large> vector(size);
        DoNotOptimize(vector.data());

        std::vector<Large> vector2(size);
        DoNotOptimize(vector2.data());

        vector.swap(vector2);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(large_vectorCreateAndSwap)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();


void large_multimapEmpty(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::multimap<Large, int> multimap;

    for (int i = 0; i < N; i++) {
        Large a{};
        a.randomize();
        multimap.insert({a, i});
    }
//nie modyfikuje kontera wiec jego tworzenie moze byc zawarte poza petla
    for (auto _ : state) {
        auto result = multimap.empty();

        DoNotOptimize(result);
    }
    state.SetComplexityN(N);

}

BENCHMARK(large_multimapEmpty)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_multimapSize(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::multimap<Large, int> multimap;

    for (int i = 0; i < N; i++) {
        Large a{};
        a.randomize();
        multimap.insert({a, i});
    }
//nie modyfikuje kontera wiec jego tworzenie moze byc zawarte poza petla
    for (auto _ : state) {
        auto result = multimap.size();

        DoNotOptimize(result);
    }
    state.SetComplexityN(N);

}

BENCHMARK(large_multimapSize)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_multimapMaxSize(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::multimap<Large, int> multimap;

    for (int i = 0; i < N; i++) {
        Large a{};
        a.randomize();
        multimap.insert({a, i});
    }
//nie modyfikuje kontera wiec jego tworzenie moze byc zawarte poza petla
    for (auto _ : state) {
        auto result = multimap.max_size();

        DoNotOptimize(result);
    }
    state.SetComplexityN(N);

}

BENCHMARK(large_multimapMaxSize)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_multimapCreate(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    for (auto _ : state) {
        std::multimap<Large, int> multimap;
        DoNotOptimize(multimap);
    }
    state.SetComplexityN(N);

}

BENCHMARK(large_multimapCreate)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_multimapCreateAndInsert(State &state) { //complexity: expected=amortized constant, received=constant
    auto N = state.range(0);

    std::multimap<Large, int> multimap;
    for(int i = 0; i<N; i++){
        Large a{};
        a.randomize();
        multimap.insert({a, i});
    }

    for (auto _ : state) {
        Large a{};
        a.randomize();
        auto randN = rand();
        multimap.insert({a, randN});

        auto result = multimap.erase(a);
        DoNotOptimize(result);
    }
    state.SetComplexityN(N);
}

BENCHMARK(large_multimapCreateAndInsert)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_multimapCreateAndErase(State &state) { //complexity: expected=amortized constant, received=constant
    auto N = state.range(0);

    std::multimap<Large, int> multimap;
    for(int i = 0; i<N; i++){
        Large a{};
        a.randomize();
        multimap.insert({a, i});
    }

    for (auto _ : state) {
        Large a{};
        a.randomize();
        auto randN = rand();
        multimap.insert({a, randN});

        auto result = multimap.erase(a);
        DoNotOptimize(result);
    }
    state.SetComplexityN(N);
}

BENCHMARK(large_multimapCreateAndErase)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_rand_benchmark(State& state) {

    for (auto _ : state) {

        auto number = rand();
        DoNotOptimize(number);
    }
}

BENCHMARK(large_rand_benchmark);

void large_multimapCreateAndClear(State &state) { //complexity: expected=linear, received=linear
    auto N = state.range(0);


    for (auto _ : state) {
        std::multimap<Large, int> multimap;
        for(int i = 0; i<N; i++){
            Large a{};
            a.randomize();
            multimap.insert({a, i});

            DoNotOptimize(multimap);

            multimap.clear();
            ClobberMemory();
        }
    }
    state.SetComplexityN(N);
}

BENCHMARK(large_multimapCreateAndClear)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_multimapSwap(State &state) { //complexity: expected=constant, received=linear
    auto N = state.range(0);

    std::multimap<Large, int> multimap;
    for(int i = 0; i<N; i++){
        Large a{};
        a.randomize();
        multimap.insert({a, i});
    }

    std::multimap<Large, int> multimap2;
    for(int i = 0; i<N; i++){
        Large a{};
        a.randomize();
        multimap2.insert({a, i});
    }

    for (auto _ : state) {
        multimap.swap(multimap2);
        DoNotOptimize(multimap);

    }
    state.SetComplexityN(N);
}
BENCHMARK(large_multimapSwap)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_multimapCount(State& state) { //complexity: expected: lgN + N(, received=N
    auto N = state.range(0);

    std::multimap<Large, int> multimap;
    for(int i = 0; i<N; i++){
        Large a{};
        a.randomize();
        multimap.insert({a, i});
    }
    Large a{};
    a.randomize();
    for(auto _ : state) {

        auto result = multimap.count(a);

        DoNotOptimize(result);
    }
    state.SetComplexityN(N);

}
BENCHMARK(large_multimapCount)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();


void large_multimapFind(State& state) { //complexity: expected: lgN, received=lgN
    auto N = state.range(0);

    std::multimap<Large, int> multimap;
    for(int i = 0; i<N; i++){
        Large a{};
        a.randomize();
        multimap.insert({a, i});
    }
    Large a{};
    a.randomize();
    for(auto _ : state) {

        auto result = multimap.find(a);

        DoNotOptimize(result);
    }

    state.SetComplexityN(N);

}

BENCHMARK(large_multimapFind)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_multimapEqualRange(State& state) { //complexity: expected=lgN, received= lgN
    auto N = state.range(0);

    std::multimap<Large, int> multimap;
    for(int i = 0; i<N; i++){
        Large a{};
        a.randomize();
        multimap.insert({a, i});
    }
    Large a{};
    a.randomize();
    for(auto _: state) {

        auto result = multimap.equal_range(a);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);

}

BENCHMARK(large_multimapEqualRange)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_multimapLowerBound(State& state) { //complexity: expected=lgN, received= lgN
    auto N = state.range(0);

    std::multimap<Large, int> multimap;
    for(int i = 0; i<N; i++){
        Large a{};
        a.randomize();
        multimap.insert({a, i});
    }
    Large a{};
    a.randomize();
    for(auto _: state) {

        auto result = multimap.lower_bound(a);

        DoNotOptimize(result);
    }

    state.SetComplexityN(N);

}

BENCHMARK(large_multimapLowerBound)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_multimapUpperBound(State& state) { //complexity: expected=lgN, received= lgN
    auto N = state.range(0);

    std::multimap<Large, int> multimap;
    for(int i = 0; i<N; i++){
        Large a{};
        a.randomize();
        multimap.insert({a, i});
    }
    Large a{};
    a.randomize();
    for(auto _: state) {

        auto result = multimap.upper_bound(a);

        DoNotOptimize(result);
    }

    state.SetComplexityN(N);

}

BENCHMARK(large_multimapUpperBound)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();


void large_unordered_multimapEmpty(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::unordered_multimap<Large, int> unordered_multimap;

    for (int i = 0; i < N; i++) {
        Large a{};
        a.randomize();
        unordered_multimap.insert({a, i});
    }
//nie modyfikuje kontera wiec jego tworzenie moze byc zawarte poza petla
    for (auto _ : state) {
        auto result = unordered_multimap.empty();

        DoNotOptimize(result);
    }
    state.SetComplexityN(N);
}

BENCHMARK(large_unordered_multimapEmpty)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_unordered_multimapSize(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::unordered_multimap<Large, int> unordered_multimap;

    for (int i = 0; i < N; i++) {
        Large a{};
        a.randomize();
        unordered_multimap.insert({a, i});
    }
//nie modyfikuje kontera wiec jego tworzenie moze byc zawarte poza petla
    for (auto _ : state) {
        auto result = unordered_multimap.size();

        DoNotOptimize(result);
    }
    state.SetComplexityN(N);
}

BENCHMARK(large_unordered_multimapSize)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_unordered_multimapMaxSize(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::unordered_multimap<Large, int> unordered_multimap;

    for (int i = 0; i < N; i++) {
        Large a{};
        a.randomize();
        unordered_multimap.insert({a, i});
    }
//nie modyfikuje kontera wiec jego tworzenie moze byc zawarte poza petla
    for (auto _ : state) {
        auto result = unordered_multimap.max_size();

        DoNotOptimize(result);
    }
    state.SetComplexityN(N);
}

BENCHMARK(large_unordered_multimapMaxSize)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_unordered_multimapCreate(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    for (auto _ : state) {
        std::unordered_multimap<Large, int> unordered_multimap;
        DoNotOptimize(unordered_multimap);
        state.SetComplexityN(N);

    }
}

BENCHMARK(large_unordered_multimapCreate)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();


void large_unordered_multimapCreateAndClear(State &state) { //complexity: expected=linear, received=linear
    auto N = state.range(0);


    for (auto _ : state) {
        std::unordered_multimap<Large, int> unordered_multimap;
        for (int i = 0; i < N; i++) {
            Large a{};
            a.randomize();
            unordered_multimap.insert({a, i});

            DoNotOptimize(unordered_multimap);

            unordered_multimap.clear();
            ClobberMemory();
        }
    }
    state.SetComplexityN(N);
}

BENCHMARK(large_unordered_multimapCreateAndClear)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_unordered_multimapCreateInsertAndErase(State &state) {
    auto N = state.range(0);

    std::unordered_multimap<Large, int> unordered_multimap;
    for (int i = 0; i < N; i++) {
        Large a{};
        a.randomize();
        unordered_multimap.insert({a, i});
    }


    for (auto _ : state) {

        Large a{};
        a.randomize();
        unordered_multimap.insert({a, 0});

        auto result = unordered_multimap.erase(a);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);

}

BENCHMARK(large_unordered_multimapCreateInsertAndErase)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_unordered_multimapSwap(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::unordered_multimap<Large, int> unordered_multimap;
    for (int i = 0; i < N; i++) {
        Large a{};
        a.randomize();
        unordered_multimap.insert({a, i});
    }

    std::unordered_multimap<Large, int> unordered_multimap_other;
    for (int i = 0; i < N; i++) {
        Large a{};
        a.randomize();
        unordered_multimap_other.insert({a, i});
    }

    for (auto _ : state) {
        unordered_multimap.swap(unordered_multimap_other);
        DoNotOptimize(unordered_multimap);
    }
    state.SetComplexityN(N);
}

BENCHMARK(large_unordered_multimapSwap)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_unordered_multimapCount(State &state) { //complexity: expected=linear, received=linear
    auto N = state.range(0);

    for (auto _ : state) {
        for (int i = 0; i < N; i++) {
            std::unordered_multimap<Large, int> unordered_multimap;

            Large a{};
            a.randomize();
            unordered_multimap.insert({a, i});

            auto result = unordered_multimap.count(a);
            DoNotOptimize(result);
        }
    }
    state.SetComplexityN(N);
}

BENCHMARK(large_unordered_multimapCount)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_unordered_multimapFind(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::unordered_multimap<Large, int> unordered_multimap;
    for (int i = 0; i < N; i++) {
        Large a{};
        a.randomize();
        unordered_multimap.insert({a, i});
    }

    for (auto _ : state) {
        Large a{};
        a.randomize();
        auto result = unordered_multimap.find(a);
        DoNotOptimize(result);
    }
    state.SetComplexityN(N);
}

BENCHMARK(large_unordered_multimapFind)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_unordered_multimapEqualRange(State& state) { //complexity: expected=linear, received=linear
    auto N = state.range(0);

    for(auto _ : state) {
        std::unordered_multimap<Large, int> unordered_multimap;
        for (int i = 0; i < N; i++) {
            Large a{};
            a.randomize();
            unordered_multimap.insert({a, i});

            auto result = unordered_multimap.equal_range(a);
            DoNotOptimize(result);
        }
    }
    state.SetComplexityN(N);

}
BENCHMARK(large_unordered_multimapEqualRange)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_unordered_multimapRehash(State& state) { //complexity: expected=linear, worst case=quadratic, received=quadratic
    auto N = state.range(0);

    for(auto _ : state) {
        std::unordered_multimap<Large, int> unordered_multimap;
        for (int i = 0; i < N; i++) {
            Large a{};
            a.randomize();
            unordered_multimap.insert({a, i});
            DoNotOptimize(unordered_multimap);

            unordered_multimap.rehash(0);
            ClobberMemory();
        }
    }
    state.SetComplexityN(N);

}
BENCHMARK(large_unordered_multimapRehash)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();

void large_unordered_multimapReserve(State& state) { //complexity: expected=linear, worst case=quadratic, received=quadratic
    auto N = state.range(0);

    for(auto _ : state) {
        std::unordered_multimap<Large, int> unordered_multimap;
        for (int i = 0; i < N; i++) {
            Large a{};
            a.randomize();
            unordered_multimap.insert({a, i});
            DoNotOptimize(unordered_multimap);

        }
        unordered_multimap.reserve(0);
        ClobberMemory();
    }
    state.SetComplexityN(N);

}
BENCHMARK(large_unordered_multimapReserve)->RangeMultiplier(2)->Range(128u, 2048u)->Complexity();
