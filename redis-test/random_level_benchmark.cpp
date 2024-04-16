#include <benchmark/benchmark.h>
#include "random_level.h"

#define __BENCHMARK(v) BENCHMARK(v)->MinWarmUpTime(5)->MinTime(10)

static void BM_zslRandomLevel(benchmark::State& state) {
  for (auto _ : state)
    zslRandomLevel();
}
__BENCHMARK(BM_zslRandomLevel);

static void BM_zslRandomLevel1(benchmark::State& state) {
  for (auto _ : state)
    zslRandomLevel1();
}
__BENCHMARK(BM_zslRandomLevel1);

static void BM_zslRandomLevel2(benchmark::State& state) {
  for (auto _ : state)
    zslRandomLevel2();
}
__BENCHMARK(BM_zslRandomLevel2);

BENCHMARK_MAIN();
