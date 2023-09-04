#include <catch2/catch_test_macros.hpp>

#include <vector>

std::vector<int> solution(int N, std::vector<int>& A) { return {}; }

TEST_CASE("Lesson 4 Counting Elements / MaxCounter", "[counting-elements]") {
  std::vector<std::vector<int>> data{
      {},
  };
  REQUIRE(solution(0, data.at(0)) == std::vector<int>{});
}
