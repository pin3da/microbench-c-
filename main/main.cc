#include <iostream>
#include <random>
#include <string>
#include <string_view>

// Bazel-dependency
#include <benchmark/benchmark.h>

std::string GenerateRandomString(int length) {
  std::string_view charset =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, charset.size() - 1);

  std::string random_string;
  random_string.reserve(length);

  for (int i = 0; i < length; ++i) {
    random_string += charset[dis(gen)];
  }

  return random_string;
}

static std::vector<std::string> StringsToConcat() {
  int num_strings = 1000;
  int max_length = 1000;
  std::vector<std::string> ret(num_strings);
  for (int i = 0; i < num_strings; ++i) {
    // TODO: Assign random lenght up to max_length.
    ret[i] = GenerateRandomString(max_length);
  }
  return ret;
}

static void BM_StringConcatV1(benchmark::State &state) {
  for (auto _ : state) {
    state.PauseTiming();
    auto data = StringsToConcat();
    state.ResumeTiming();
    std::string result;
    for (auto &s : data) {
      result += s;
    }
  }
}
BENCHMARK(BM_StringConcatV1);

static void BM_StringConcatV2(benchmark::State &state) {
  for (auto _ : state) {
    state.PauseTiming();
    auto data = StringsToConcat();
    state.ResumeTiming();
    std::string result;

    for (auto &s : data) {
      for (auto &c : s) {
        result.push_back(c);
      }
    }
  }
}
BENCHMARK(BM_StringConcatV2);

BENCHMARK_MAIN();