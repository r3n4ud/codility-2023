#include <catch2/catch_test_macros.hpp>

#include <iostream>

#include <algorithm>
#include <vector>

int solution(std::vector<int>& A) {
  int result = 0;
  if (!A.empty() && (A.size() % 2 == 1)) {
    if (A.size() == 1) {
      result = A.at(0);
    }
    std::sort(A.begin(), A.end());
    for (auto it = A.begin(); it < A.end() - 1; it = it + 2) {
      if (*it != *(it + 1)) {
        result = *it;
        break;
      } else if ((it + 2) == A.end() - 1) {
        result = A.back();
      }
    }
  }
  return result;
}

TEST_CASE("Lesson 2 Arrays / OddOccurrencesInArray", "[arrays]") {
  std::vector<std::vector<int>> data{{9, 3, 9, 3, 9, 7, 9},
                                     {1, 2, 3, 4, 9, 6, 4, 3, 2, 1, 9},
                                     {},
                                     {1, 2, 2, 1},
                                     {1, 1, 1, 1, 1, 1, 1, 1, 1}};
  REQUIRE(solution(data.at(0)) == 7);
  REQUIRE(solution(data.at(1)) == 6);
  REQUIRE(solution(data.at(2)) == 0);
  REQUIRE(solution(data.at(3)) == 0);
  REQUIRE(solution(data.at(4)) == 1);
}
