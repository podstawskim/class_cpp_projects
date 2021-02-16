//
// Created by Michał Podstawski on 08/12/2020.
//

#include "BenchIncludes.h"
#include "Medium.h"
#include <vector>
#include <unordered_map>
#include <map>


void medium_vectorAt(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Medium> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector.at(0));
    }

    state.SetComplexityN(N);
}

BENCHMARK(medium_vectorAt)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_vectorOperator(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Medium> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector[0]);
    }

    state.SetComplexityN(N);
}

BENCHMARK(medium_vectorOperator)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_vectorFront(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Medium> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector.front());
    }

    state.SetComplexityN(N);
}

BENCHMARK(medium_vectorFront)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_vectorBack(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Medium> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector.back());
    }

    state.SetComplexityN(N);
}

BENCHMARK(medium_vectorBack)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_vectorData(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Medium> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector.data());
    }

    state.SetComplexityN(N);
}

BENCHMARK(medium_vectorData)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_vectorEmpty(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Medium> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector.empty());
    }

    state.SetComplexityN(N);
}

BENCHMARK(medium_vectorEmpty)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_vector_size(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Medium> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector.size());
    }

    state.SetComplexityN(N);
}

BENCHMARK(medium_vector_size)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_vectorMaxSize(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Medium> vector(size);

    for (auto _: state) {
        DoNotOptimize(vector.max_size());
    }

    state.SetComplexityN(N);
}

BENCHMARK(medium_vectorMaxSize)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_vectorReserve(State &state) { //complexity: at most linear
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Medium> vector(size);

    for (auto _ : state) {
        for (int i = 0; i < size; i++)
            vector.reserve(i);
        ClobberMemory();
    }
    state.SetComplexityN(N);

}

BENCHMARK(medium_vectorReserve)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_vectorCapacity(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Medium> vector(size);

    for (auto _ : state) {
        DoNotOptimize(vector.capacity());
    }
    state.SetComplexityN(N);

}

BENCHMARK(medium_vectorCapacity)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_vectorShrinkToFit(State &state) { //complexity: at most linear
    auto N = state.range(0);
    auto size = (std::size_t) N;

    std::vector<Medium> vector(size);

    for (auto _ : state) {

        for (int i = 0; i < size; i++)
            vector.shrink_to_fit();
    }
    state.SetComplexityN(N);
}

BENCHMARK(medium_vectorShrinkToFit)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_vector_create(State &state) { //complexity: linear

    auto N = state.range(0);
    auto size = (std::size_t) N;

    for (auto _ : state) {

        std::vector<Medium> vector(size);

        DoNotOptimize(vector);
    }

    state.SetComplexityN(N);
}

BENCHMARK(medium_vector_create)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_vectorCreateAndClear(State &state) { //complexity: linear in a size of container
    auto N = state.range(0);
    auto size = (std::size_t) N;

    for (auto _ : state) {
        std::vector<Medium> vector(size);
        DoNotOptimize(vector.data());

        vector.clear();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(medium_vectorCreateAndClear)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_vectorCreateAndInsert(State &state) { //complexity: linear
    auto N = state.range(0);
    auto size = (std::size_t) N;

    for (auto _ : state) {
        std::vector<Medium> vector(size);
        DoNotOptimize(vector.data());

        Medium a{};
        a.randomize();

        vector.insert(vector.begin(), a);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(medium_vectorCreateAndInsert)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_vectorCreateAndErase(State &state) { //complexity: linear
    auto N = state.range(0);
    auto size = (std::size_t) N;

    for (auto _ : state) {
        std::vector<Medium> vector(size);
        DoNotOptimize(vector.data());

        vector.erase(vector.begin());
        ClobberMemory();
    }

    state.SetComplexityN(N);

}

BENCHMARK(medium_vectorCreateAndErase)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_vectorCreateAndPush_Back(State &state) { //complexity: linear

    auto N = state.range(0);
    auto size = (std::size_t) N;

    for (auto _ : state) {

        std::vector<Medium> vector(size);
        DoNotOptimize(vector.data());

        Medium a{};
        a.randomize();

        vector.push_back(a);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(medium_vectorCreateAndPush_Back)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_vectorCreateAndPopBack(State &state) { //complexity: constant
    auto N = state.range(0);
    auto size = (std::size_t) N;

    for (auto _ : state) {

        std::vector<Medium> vector(size);
        DoNotOptimize(vector.data());

        vector.pop_back();
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(medium_vectorCreateAndPopBack)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_vectorCreateAndResize(State &state) {
    auto N = state.range(0);
    auto size = (std::size_t) N;

    for (auto _ : state) {

        std::vector<Medium> vector(size);
        DoNotOptimize(vector.data());

        vector.resize(10);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(medium_vectorCreateAndResize)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_vectorCreateAndSwap(State &state) {
    auto N = state.range(0);
    auto size = (std::size_t) N;

    for (auto _ : state) {
        std::vector<Medium> vector(size);
        DoNotOptimize(vector.data());

        std::vector<Medium> vector2(size);
        DoNotOptimize(vector2.data());

        vector.swap(vector2);
        ClobberMemory();
    }

    state.SetComplexityN(N);
}

BENCHMARK(medium_vectorCreateAndSwap)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();


void medium_multimapEmpty(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::multimap<Medium, int> multimap;

    for (int i = 0; i < N; i++) {
        Medium a{};
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

BENCHMARK(medium_multimapEmpty)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_multimapSize(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::multimap<Medium, int> multimap;

    for (int i = 0; i < N; i++) {
        Medium a{};
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

BENCHMARK(medium_multimapSize)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_multimapMaxSize(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::multimap<Medium, int> multimap;

    for (int i = 0; i < N; i++) {
        Medium a{};
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

BENCHMARK(medium_multimapMaxSize)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_multimapCreate(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    for (auto _ : state) {
        std::multimap<Medium, int> multimap;
        DoNotOptimize(multimap);
    }
    state.SetComplexityN(N);

}

BENCHMARK(medium_multimapCreate)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_multimapCreateAndInsert(State &state) { //complexity: expected=amortized constant, received=constant
    auto N = state.range(0);

    std::multimap<Medium, int> multimap;
    for(int i = 0; i<N; i++){
        Medium a{};
        a.randomize();
        multimap.insert({a, i});
    }

    for (auto _ : state) {
        Medium a{};
        a.randomize();
        auto randN = rand();
        multimap.insert({a, randN});

        auto result = multimap.erase(a);
        DoNotOptimize(result);
    }
    state.SetComplexityN(N);
}

BENCHMARK(medium_multimapCreateAndInsert)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_multimapCreateAndErase(State &state) { //complexity: expected=amortized constant, received=constant
    auto N = state.range(0);

    std::multimap<Medium, int> multimap;
    for(int i = 0; i<N; i++){
        Medium a{};
        a.randomize();
        multimap.insert({a, i});
    }

    for (auto _ : state) {
        Medium a{};
        a.randomize();
        auto randN = rand();
        multimap.insert({a, randN});

        auto result = multimap.erase(a);
        DoNotOptimize(result);
    }
    state.SetComplexityN(N);
}

BENCHMARK(medium_multimapCreateAndErase)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_rand_benchmark(State& state) {

    for (auto _ : state) {

        auto number = rand();
        DoNotOptimize(number);
    }
}

BENCHMARK(medium_rand_benchmark);

void medium_multimapCreateAndClear(State &state) { //complexity: expected=linear, received=linear
    auto N = state.range(0);


    for (auto _ : state) {
        std::multimap<Medium, int> multimap;
        for(int i = 0; i<N; i++){
            Medium a{};
            a.randomize();
            multimap.insert({a, i});

            DoNotOptimize(multimap);

            multimap.clear();
            ClobberMemory();
        }
    }
    state.SetComplexityN(N);
}

BENCHMARK(medium_multimapCreateAndClear)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_multimapSwap(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::multimap<Medium, int> multimap;
    for(int i = 0; i<N; i++){
        Medium a{};
        a.randomize();
        multimap.insert({a, i});
    }

    std::multimap<Medium, int> multimap2;
    for(int i = 0; i<N; i++){
        Medium a{};
        a.randomize();
        multimap2.insert({a, i});
    }

    for (auto _ : state) {
        multimap.swap(multimap2);
        DoNotOptimize(multimap);

    }
    state.SetComplexityN(N);
}
BENCHMARK(medium_multimapSwap)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_multimapCount(State& state) { //complexity: expected: lgN + N(, received=lgN
    auto N = state.range(0);

    std::multimap<Medium, int> multimap;
    for(int i = 0; i<N; i++){
        Medium a{};
        a.randomize();
        multimap.insert({a, i});
    }

    Medium a{};
    a.randomize();

    for(auto _ : state) {

        auto result = multimap.count(a);
        DoNotOptimize(result);
    }
    state.SetComplexityN(N);

}
BENCHMARK(medium_multimapCount)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();


void medium_multimapFind(State& state) { //complexity: expected: lgN, received=lgN
    auto N = state.range(0);

    std::multimap<Medium, int> multimap;
    for(int i = 0; i<N; i++){
        Medium a{};
        a.randomize();
        multimap.insert({a, i});
    }

    Medium a{};
    a.randomize();
    for(auto _ : state) {

        auto result = multimap.find(a);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);

}

BENCHMARK(medium_multimapFind)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_multimapEqualRange(State& state) { //complexity: expected=lgN, received= lgN
    auto N = state.range(0);

    std::multimap<Medium, int> multimap;
    for(int i = 0; i<N; i++){
        Medium a{};
        a.randomize();
        multimap.insert({a, i});
    }

    Medium a{};
    a.randomize();
    for(auto _: state) {

        auto result = multimap.equal_range(a);

        DoNotOptimize(result);
    }

    state.SetComplexityN(N);

}

BENCHMARK(medium_multimapEqualRange)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_multimapLowerBound(State& state) { //complexity: expected=lgN, received= lgN
    auto N = state.range(0);

    std::multimap<Medium, int> multimap;
    for(int i = 0; i<N; i++){
        Medium a{};
        a.randomize();
        multimap.insert({a, i});
    }

    Medium a{};
    a.randomize();
    for(auto _: state) {

        auto result = multimap.lower_bound(a);

        DoNotOptimize(result);
    }

    state.SetComplexityN(N);

}

BENCHMARK(medium_multimapLowerBound)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_multimapUpperBound(State& state) { //complexity: expected=lgN, received= lgN
    auto N = state.range(0);

    std::multimap<Medium, int> multimap;
    for(int i = 0; i<N; i++){
        Medium a{};
        a.randomize();
        multimap.insert({a, i});
    }
    Medium a{};
    a.randomize();

    for(auto _: state) {
        auto result = multimap.upper_bound(a);

        DoNotOptimize(result);
    }

    state.SetComplexityN(N);

}

BENCHMARK(medium_multimapUpperBound)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();


void medium_unordered_multimapEmpty(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::unordered_multimap<Medium, int> unordered_multimap;

    for (int i = 0; i < N; i++) {
        Medium a{};
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

BENCHMARK(medium_unordered_multimapEmpty)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_unordered_multimapSize(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::unordered_multimap<Medium, int> unordered_multimap;

    for (int i = 0; i < N; i++) {
        Medium a{};
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

BENCHMARK(medium_unordered_multimapSize)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_unordered_multimapMaxSize(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::unordered_multimap<Medium, int> unordered_multimap;

    for (int i = 0; i < N; i++) {
        Medium a{};
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

BENCHMARK(medium_unordered_multimapMaxSize)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_unordered_multimapCreate(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    for (auto _ : state) {
        std::unordered_multimap<Medium, int> unordered_multimap;
        DoNotOptimize(unordered_multimap);
        state.SetComplexityN(N);

    }
}

BENCHMARK(medium_unordered_multimapCreate)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();


void medium_unordered_multimapCreateAndClear(State &state) { //complexity: expected=linear, received=linear
    auto N = state.range(0);


    for (auto _ : state) {
        std::unordered_multimap<Medium, int> unordered_multimap;
        for (int i = 0; i < N; i++) {
            Medium a{};
            a.randomize();
            unordered_multimap.insert({a, i});

            DoNotOptimize(unordered_multimap);

            unordered_multimap.clear();
            ClobberMemory();
        }
    }
    state.SetComplexityN(N);
}

BENCHMARK(medium_unordered_multimapCreateAndClear)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_unordered_multimapCreateInsertAndErase(State &state) {
    auto N = state.range(0);

    std::unordered_multimap<Medium, int> unordered_multimap;
    for (int i = 0; i < N; i++) {
        Medium a{};
        a.randomize();
        unordered_multimap.insert({a, i});
    }

    for (auto _ : state) {
        auto randN = rand();

        Medium a{};
        a.randomize();
        unordered_multimap.insert({a, randN});

        auto result = unordered_multimap.erase(a);
        DoNotOptimize(result);
    }

    state.SetComplexityN(N);

}

BENCHMARK(medium_unordered_multimapCreateInsertAndErase)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_unordered_multimapSwap(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::unordered_multimap<Medium, int> unordered_multimap;
    for (int i = 0; i < N; i++) {
        Medium a{};
        a.randomize();
        unordered_multimap.insert({a, i});
    }

    std::unordered_multimap<Medium, int> unordered_multimap_other;
    for (int i = 0; i < N; i++) {
        Medium a{};
        a.randomize();
        unordered_multimap_other.insert({a, i});
    }

    for (auto _ : state) {
        unordered_multimap.swap(unordered_multimap_other);
        DoNotOptimize(unordered_multimap);
    }
    state.SetComplexityN(N);
}

BENCHMARK(medium_unordered_multimapSwap)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_unordered_multimapCount(State &state) { //complexity: expected=linear, received=linear
    auto N = state.range(0);

    for (auto _ : state) {
        for (int i = 0; i < N; i++) {
            std::unordered_multimap<Medium, int> unordered_multimap;
            Medium a{};
            a.randomize();
            unordered_multimap.insert({a, i});

            auto result = unordered_multimap.count(a);
            DoNotOptimize(result);
        }
    }
    state.SetComplexityN(N);
}

BENCHMARK(medium_unordered_multimapCount)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_unordered_multimapFind(State &state) { //complexity: expected=constant, received=constant
    auto N = state.range(0);

    std::unordered_multimap<Medium, int> unordered_multimap;
    for (int i = 0; i < N; i++) {
        Medium a{};
        a.randomize();
        unordered_multimap.insert({a, i});
    }

    for (auto _ : state) {
        Medium a{};
        a.randomize();
        auto result = unordered_multimap.find(a);
        DoNotOptimize(result);
    }
    state.SetComplexityN(N);
}

BENCHMARK(medium_unordered_multimapFind)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_unordered_multimapEqualRange(State& state) { //complexity: expected=linear, received=linear
    auto N = state.range(0);

    for(auto _ : state) {
        for (int i = 0; i < N; i++) {
            std::unordered_multimap<Medium, int> unordered_multimap;

            Medium a{};
            a.randomize();
            unordered_multimap.insert({a, i});

            auto result = unordered_multimap.equal_range(a);
            DoNotOptimize(result);
        }
    }
    state.SetComplexityN(N);

}
BENCHMARK(medium_unordered_multimapEqualRange)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_unordered_multimapRehash(State& state) { //complexity: expected=linear, worst case=quadratic, received=quadratic
    auto N = state.range(0);

    for(auto _ : state) {
        std::unordered_multimap<Medium, int> unordered_multimap;
        for (int i = 0; i < N; i++) {
            Medium a{};
            a.randomize();
            unordered_multimap.insert({a, i});

        }
        unordered_multimap.rehash(0);
        ClobberMemory();
    }
    state.SetComplexityN(N);

}
BENCHMARK(medium_unordered_multimapRehash)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();

void medium_unordered_multimapReserve(State& state) { //complexity: expected=linear, worst case=quadratic, received=quadratic
    auto N = state.range(0);

    for(auto _ : state) {
        std::unordered_multimap<Medium, int> unordered_multimap;
        for (int i = 0; i < N; i++) {
            Medium a{};
            a.randomize();
            unordered_multimap.insert({a, i});
            DoNotOptimize(unordered_multimap);

        }
        unordered_multimap.reserve(0);
        ClobberMemory();
    }
    state.SetComplexityN(N);

}
BENCHMARK(medium_unordered_multimapReserve)->RangeMultiplier(2)->Range(32, 2048u)->Complexity();



