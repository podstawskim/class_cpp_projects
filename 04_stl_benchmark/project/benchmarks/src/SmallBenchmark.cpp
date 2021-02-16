//
// Created by Michał Podstawski on 01/12/2020.
//
#include "BenchIncludes.h"
#include "Small.h"
#include <vector>
#include <unordered_map>
#include <map>


void vectorAt(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Small> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector.at(0));
    }

    state.SetComplexityN(N);
}

BENCHMARK(vectorAt)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void vectorOperator(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Small> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector[0]);
    }

    state.SetComplexityN(N);
}

BENCHMARK(vectorOperator)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void vectorFront(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Small> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector.front());
    }

    state.SetComplexityN(N);
}

BENCHMARK(vectorFront)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void vectorBack(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Small> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector.back());
    }

    state.SetComplexityN(N);
}

BENCHMARK(vectorBack)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void vectorData(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Small> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector.data());
    }

    state.SetComplexityN(N);
}

BENCHMARK(vectorData)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void vectorEmpty(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Small> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector.empty());
    }

    state.SetComplexityN(N);
}

BENCHMARK(vectorEmpty)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void vector_size(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Small> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector.size());
    }

    state.SetComplexityN(N);
}

BENCHMARK(vector_size)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void vectorMaxSize(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Small> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector.max_size());
    }

    state.SetComplexityN(N);
}

BENCHMARK(vectorMaxSize)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void vectorReserve(State &state) { //complexity: at most linear
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Small> vector(size);

    for (auto _ : state) {
        for (int i = 0; i < size; i++)
            vector.reserve(i);
    }
    state.SetComplexityN(N);

}

BENCHMARK(vectorReserve)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void vectorCapacity(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Small> vector(size);

    for (auto _ : state) {
        DoNotOptimize(vector.capacity());
    }
    state.SetComplexityN(N);

}

BENCHMARK(vectorCapacity)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void vectorShrinkToFit(State &state) { //complexity: at most linear
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Small> vector(size);

    for (auto _ : state) {

        for (int i = 0; i < size; i++)
            vector.shrink_to_fit();
    }
    state.SetComplexityN(N);
}

BENCHMARK(vectorShrinkToFit)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void vector_create(State &state) { //complexity: linear

    auto N = state.range(0);
    auto size = (std::size_t) N;

    for (auto _ : state) {

        std::vector<Small> vector(size);

        DoNotOptimize(vector);
    }

    state.SetComplexityN(N);
}

BENCHMARK(vector_create)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void vectorCreateAndClear(State &state) { //complexity: linear in a size of container
    auto N = state.range(0);
    auto size = (std::size_t) N;

    for (auto _ : state) {
        std::vector<Small> vector(size);
        DoNotOptimize(vector.data());

        vector.clear();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(vectorCreateAndClear)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void vectorCreateAndInsert(State &state) { //complexity: linear
    auto N = state.range(0);
    auto size = (std::size_t) N;

    for (auto _ : state) {
        std::vector<Small> vector(size);
        DoNotOptimize(vector.data());

        Small a{};
        a.randomize();

        vector.insert(vector.begin(), a);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(vectorCreateAndInsert)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void vectorCreateAndErase(State &state) { //complexity: linear
    auto N = state.range(0);
    auto size = (std::size_t) N;

    for (auto _ : state) {
        std::vector<Small> vector(size);
        DoNotOptimize(vector.data());

        vector.erase(vector.begin());
        ClobberMemory();
    }

    state.SetComplexityN(N);

}

BENCHMARK(vectorCreateAndErase)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void vectorCreateAndPush_Back(State &state) { //complexity: linear

    auto N = state.range(0);
    auto size = (std::size_t) N;

    for (auto _ : state) {

        std::vector<Small> vector(size);
        DoNotOptimize(vector.data());

        Small a{};
        a.randomize();

        vector.push_back(a);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(vectorCreateAndPush_Back)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void vectorCreateAndPopBack(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    for (auto _ : state) {

        std::vector<Small> vector(size);
        DoNotOptimize(vector.data());

        vector.pop_back();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(vectorCreateAndPopBack)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void vectorCreateAndResize(State &state) {
    auto N = state.range(0);
    auto size = (std::size_t) N;

    for (auto _ : state) {

        std::vector<Small> vector(size);
        DoNotOptimize(vector.data());

        vector.resize(10);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(vectorCreateAndResize)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void vectorCreateAndSwap(State &state) {
    auto N = state.range(0);
    auto size = (std::size_t) N;


    for (auto _ : state) {
        std::vector<Small> vector(size);
        DoNotOptimize(vector.data());

        std::vector<Small> vector2(size);
        DoNotOptimize(vector2.data());

        vector.swap(vector2);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(vectorCreateAndSwap)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();


void multimapEmpty(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::multimap<Small, int> multimap;

    for (int i = 0; i < N; i++) {
        Small a{};
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

BENCHMARK(multimapEmpty)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void multimapSize(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::multimap<Small, int> multimap;

    for (int i = 0; i < N; i++) {
        Small a{};
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

BENCHMARK(multimapSize)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void multimapMaxSize(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::multimap<Small, int> multimap;

    for (int i = 0; i < N; i++) {
        Small a{};
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

BENCHMARK(multimapMaxSize)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void multimapCreate(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    for (auto _ : state) {
        std::multimap<Small, int> multimap;
        DoNotOptimize(multimap);
    }
    state.SetComplexityN(N);

}

BENCHMARK(multimapCreate)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void multimapCreateAndInsert(State &state) { //complexity: expected=amortized constant, received=constant
    auto N = state.range(0);

    std::multimap<Small, int> multimap;
    for(int i = 0; i<N; i++){
        Small a{};
        a.randomize();
        multimap.insert({a, i});
    }

    for (auto _ : state) {
        Small a{};
        a.randomize();
        auto randN = rand();
        multimap.insert({a, randN});

        auto result = multimap.erase(a);
        DoNotOptimize(result);
    }
    state.SetComplexityN(N);
}

BENCHMARK(multimapCreateAndInsert)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void multimapCreateAndErase(State &state) { //complexity: expected=amortized constant, received=constant
    auto N = state.range(0);

    std::multimap<Small, int> multimap;
    for(int i = 0; i<N; i++){
        Small a{};
        a.randomize();
        multimap.insert({a, i});
    }

    for (auto _ : state) {
        Small a{};
        a.randomize();
        auto randN = rand();
        multimap.insert({a, randN});

        auto result = multimap.erase(a);
        DoNotOptimize(result);
    }
    state.SetComplexityN(N);
}

BENCHMARK(multimapCreateAndErase)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void rand_benchmark(State& state) {

    for (auto _ : state) {

        auto number = rand();
        DoNotOptimize(number);
    }
}

BENCHMARK(rand_benchmark);

void multimapCreateAndClear(State &state) { //complexity: expected=linear, received=linear
    auto N = state.range(0);


    for (auto _ : state) {
        std::multimap<Small, int> multimap;
        for(int i = 0; i<N; i++){
            Small a{};
            a.randomize();
            multimap.insert({a, i});

            DoNotOptimize(multimap);

            multimap.clear();
            ClobberMemory();
        }
    }
    state.SetComplexityN(N);
}

BENCHMARK(multimapCreateAndClear)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void multimapSwap(State &state) { //complexity: expected=constant, received=linear
    auto N = state.range(0);

    std::multimap<Small, int> multimap;
    for(int i = 0; i<N; i++){
        Small a{};
        a.randomize();
        multimap.insert({a, i});
    }

    std::multimap<Small, int> multimap2;
    for(int i = 0; i<N; i++){
        Small a{};
        a.randomize();
        multimap2.insert({a, i});
    }

    for (auto _ : state) {
        multimap.swap(multimap2);
        DoNotOptimize(multimap);

    }
    state.SetComplexityN(N);
}
BENCHMARK(multimapSwap)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void multimapCount(State& state) { //complexity: expected: lgN + N(, received=N
    auto N = state.range(0);

    std::multimap<Small, int> multimap;
    for(int i = 0; i<N; i++){
        Small a{};
        a.randomize();
        multimap.insert({a, i});
    }

    for(auto _ : state) {
        Small a{};
        a.randomize();
        auto result = multimap.count(a);

        DoNotOptimize(result);
    }
    state.SetComplexityN(N);

}
BENCHMARK(multimapCount)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();


void multimapFind(State& state) { //complexity: expected: lgN, received=lgN
    auto N = state.range(0);

    std::multimap<Small, int> multimap;
    for(int i = 0; i<N; i++){
        Small a{};
        a.randomize();
        multimap.insert({a, i});
    }

    for(auto _ : state) {
        Small a{};
        a.randomize();
        auto result = multimap.find(a);

        DoNotOptimize(result);
    }

    state.SetComplexityN(N);

}

BENCHMARK(multimapFind)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void multimapEqualRange(State& state) { //complexity: expected=lgN, received= lgN
    auto N = state.range(0);

    std::multimap<Small, int> multimap;
    for(int i = 0; i<N; i++){
        Small a{};
        a.randomize();
        multimap.insert({a, i});
    }

    for(auto _: state) {
        Small a{};
        a.randomize();
        auto result = multimap.equal_range(a);

        DoNotOptimize(result);
    }

    state.SetComplexityN(N);

}

BENCHMARK(multimapEqualRange)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void multimapLowerBound(State& state) { //complexity: expected=lgN, received= lgN
    auto N = state.range(0);

    std::multimap<Small, int> multimap;
    for(int i = 0; i<N; i++){
        Small a{};
        a.randomize();
        multimap.insert({a, i});
    }

    for(auto _: state) {
        Small a{};
        a.randomize();
        auto result = multimap.lower_bound(a);

        DoNotOptimize(result);
    }

    state.SetComplexityN(N);

}

BENCHMARK(multimapLowerBound)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void multimapUpperBound(State& state) { //complexity: expected=lgN, received= lgN
    auto N = state.range(0);

    std::multimap<Small, int> multimap;
    for(int i = 0; i<N; i++){
        Small a{};
        a.randomize();
        multimap.insert({a, i});
    }

    for(auto _: state) {
        Small a{};
        a.randomize();
        auto result = multimap.upper_bound(a);

        DoNotOptimize(result);
    }

    state.SetComplexityN(N);

}

BENCHMARK(multimapUpperBound)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();


void unordered_multimapEmpty(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::unordered_multimap<Small, int> unordered_multimap;

    for (int i = 0; i < N; i++) {
        Small a{};
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

BENCHMARK(unordered_multimapEmpty)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void unordered_multimapSize(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::unordered_multimap<Small, int> unordered_multimap;

    for (int i = 0; i < N; i++) {
        Small a{};
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

BENCHMARK(unordered_multimapSize)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void unordered_multimapMaxSize(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::unordered_multimap<Small, int> unordered_multimap;

    for (int i = 0; i < N; i++) {
        Small a{};
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

BENCHMARK(unordered_multimapMaxSize)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void unordered_multimapCreate(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    for (auto _ : state) {
        std::unordered_multimap<Small, int> unordered_multimap;
        DoNotOptimize(unordered_multimap);
        state.SetComplexityN(N);

    }
}

BENCHMARK(unordered_multimapCreate)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();


void unordered_multimapCreateAndClear(State &state) { //complexity: expected=linear, received=linear
    auto N = state.range(0);


    for (auto _ : state) {
        std::unordered_multimap<Small, int> unordered_multimap;
        for (int i = 0; i < N; i++) {
            Small a{};
            a.randomize();
            unordered_multimap.insert({a, i});

            DoNotOptimize(unordered_multimap);

            unordered_multimap.clear();
            ClobberMemory();
        }
    }
    state.SetComplexityN(N);
}

BENCHMARK(unordered_multimapCreateAndClear)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void unordered_multimapCreateInsertAndErase(State &state) {
    auto N = state.range(0);

    std::unordered_multimap<Small, int> unordered_multimap;
    for (int i = 0; i < N; i++) {
        Small a{};
        a.randomize();
        unordered_multimap.insert({a, i});
    }

    for (auto _ : state) {
        auto randN = rand();

        Small a{};
        a.randomize();
        unordered_multimap.insert({a, randN});

        auto result = unordered_multimap.erase(a);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);

}

BENCHMARK(unordered_multimapCreateInsertAndErase)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void unordered_multimapSwap(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::unordered_multimap<Small, int> unordered_multimap;
    for (int i = 0; i < N; i++) {
        Small a{};
        a.randomize();
        unordered_multimap.insert({a, i});
    }

    std::unordered_multimap<Small, int> unordered_multimap_other;
    for (int i = 0; i < N; i++) {
        Small a{};
        a.randomize();
        unordered_multimap_other.insert({a, i});
    }

    for (auto _ : state) {
        unordered_multimap.swap(unordered_multimap_other);
        DoNotOptimize(unordered_multimap);
    }
    state.SetComplexityN(N);
}

BENCHMARK(unordered_multimapSwap)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void unordered_multimapCount(State &state) { //complexity: expected=linear, received=linear
    auto N = state.range(0);

    for (auto _ : state) {
        for (int i = 0; i < N; i++) {
            std::unordered_multimap<Small, int> unordered_multimap;

            Small a{};
            a.randomize();
            unordered_multimap.insert({a, i});

            auto result = unordered_multimap.count(a);
            DoNotOptimize(result);
        }
    }
    state.SetComplexityN(N);
}

BENCHMARK(unordered_multimapCount)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void unordered_multimapFind(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::unordered_multimap<Small, int> unordered_multimap;
    for (int i = 0; i < N; i++) {
        Small a{};
        a.randomize();
        unordered_multimap.insert({a, i});
    }

    for (auto _ : state) {
        Small a{};
        a.randomize();
        auto result = unordered_multimap.find(a);
        DoNotOptimize(result);
    }
    state.SetComplexityN(N);
}

BENCHMARK(unordered_multimapFind)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void unordered_multimapEqualRange(State& state) { //complexity: expected=linear, received=linear
    auto N = state.range(0);

    for(auto _ : state) {
        for (int i = 0; i < N; i++) {
            std::unordered_multimap<Small, int> unordered_multimap;

            Small a{};
            a.randomize();
            unordered_multimap.insert({a, i});

            auto result = unordered_multimap.equal_range(a);
            DoNotOptimize(result);
        }
    }
    state.SetComplexityN(N);

}
BENCHMARK(unordered_multimapEqualRange)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void unordered_multimapRehash(State& state) { //complexity: expected=linear, worst case=quadratic, received=quadratic
    auto N = state.range(0);

    for(auto _ : state) {
        for (int i = 0; i < N; i++) {
            std::unordered_multimap<Small, int> unordered_multimap;
            Small a{};
            a.randomize();
            unordered_multimap.insert({a, i});
            DoNotOptimize(unordered_multimap);

            unordered_multimap.rehash(i);
            ClobberMemory();

        }
    }
    state.SetComplexityN(N);

}
BENCHMARK(unordered_multimapRehash)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

void unordered_multimapReserve(State& state) { //complexity: expected=linear, worst case=quadratic, received=quadratic
    auto N = state.range(0);

    for(auto _ : state) {
        std::unordered_multimap<Small, int> unordered_multimap;
        for (int i = 0; i < N; i++) {
            Small a{};
            a.randomize();
            unordered_multimap.insert({a, i});
            DoNotOptimize(unordered_multimap);

            unordered_multimap.reserve(i);
            ClobberMemory();
        }

    }
    state.SetComplexityN(N);

}
BENCHMARK(unordered_multimapReserve)->RangeMultiplier(2)->Range(1u, 2048u)->Complexity();

