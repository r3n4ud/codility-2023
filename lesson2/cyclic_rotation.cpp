#include <catch2/catch_test_macros.hpp>

#include <vector>

std::vector<int> solution(std::vector<int>& A, int K) {
  if (!A.empty()) {
    for (int i = 0; i < K; ++i) {
      A.insert(A.begin(), A.back());
      A.pop_back();
    }
  }
  return A;
}

TEST_CASE("Lesson 2 Arrays / CyclicRotation", "[arrays]") {
  std::vector<std::vector<int>> data{{1, 2, 3, 4}, {3, 8, 9, 7, 6}, {1, 2, 3, 4}};
  REQUIRE(solution(data.at(0), 1) == std::vector<int>{4, 1, 2, 3});
  REQUIRE(solution(data.at(1), 3) == std::vector<int>{9, 7, 6, 3, 8});
  REQUIRE(solution(data.at(2), 4) == std::vector<int>{1, 2, 3, 4});
}
