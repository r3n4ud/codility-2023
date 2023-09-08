#include <algorithm>
#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <vector>

std::vector<int> solution(int N, std::vector<int>& A) {
  std::vector<int> result(N, 0);
  int max = 0;

  for (auto item : A) {
    if (item == N + 1) {
      std::fill(result.begin(), result.end(), max);
    } else {
      int val = result.at(item - 1) + 1;
      result.at(item - 1) = val;
      if (val > max) max = val;
    }
  }

  return result;
}

TEST_CASE("Lesson 4 Counting Elements / MaxCounter", "[counting-elements]") {
  std::vector<std::vector<int>> data{
      {3, 4, 4, 6, 1, 4, 4},
  };
  REQUIRE(solution(5, data.at(0)) == std::vector<int>{3, 2, 2, 4, 2});
}
