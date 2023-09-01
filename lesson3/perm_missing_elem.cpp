#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <vector>

int solution(std::vector<int>& A) {
  int result = 1;
  if (!A.empty()) {
    std::sort(A.begin(), A.end());
    if (A.front() != 1) {
      result = 1;
    } else if (A.back() != A.size() + 1) {
      result = A.size() + 1;
    } else {
      auto it = std::adjacent_find(A.begin(), A.end(), [](auto l, auto r) { return (l + 1 != r); });
      result = *it + 1;
    }
  }
  return result;
}

TEST_CASE("Lesson 3 Time Complexity / PermMissingElem", "[timecomplexity]") {
  std::vector<std::vector<int>> data{
      {2, 3, 1, 5},          {2, 3, 4, 5, 6, 7}, {},  {1, 3, 4},
      {1, 5, 4, 2, 3, 8, 7}, {1, 2, 3, 5},       {2}, {1},
  };
  REQUIRE(solution(data.at(0)) == 4);
  REQUIRE(solution(data.at(1)) == 1);
  REQUIRE(solution(data.at(2)) == 1);
  REQUIRE(solution(data.at(3)) == 2);
  REQUIRE(solution(data.at(4)) == 6);
  REQUIRE(solution(data.at(5)) == 4);
  REQUIRE(solution(data.at(6)) == 1);
}
