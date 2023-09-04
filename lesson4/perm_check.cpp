#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <set>
#include <vector>

int solution(std::vector<int>& A) {
  int result = 0;
  size_t input_size = A.size();
  if (!A.empty()) {
    std::set<int> s(A.begin(), A.end());
    if (*s.begin() == 1 && (input_size == s.size())) {
      auto it = std::adjacent_find(s.begin(), s.end(), [](int l, int r) { return r != l + 1; });
      if ((input_size == 1) || (it == s.end())) result = 1;
    }  // else we have duplicates!
  }
  return result;
}

TEST_CASE("Lesson 4 Counting Elements / PermCheck", "[counting-elements]") {
  std::vector<std::vector<int>> data{{4, 1, 3, 2}, {4, 1, 3}, {2}, {4, 1, 3, 3}, {1}};
  REQUIRE(solution(data.at(0)) == 1);
  REQUIRE(solution(data.at(1)) == 0);
  REQUIRE(solution(data.at(2)) == 0);
  REQUIRE(solution(data.at(3)) == 0);
  REQUIRE(solution(data.at(4)) == 1);
}
