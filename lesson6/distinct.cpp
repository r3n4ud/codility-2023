#include <catch2/catch_test_macros.hpp>

#include <set>
#include <vector>

int solution(std::vector<int>& A) {
  std::set s(A.begin(), A.end());
  return s.size();
}

TEST_CASE("Lesson 6 Sorting / Distinct", "[sorting]") {
  std::vector<std::vector<int>> data{{2, 1, 1, 2, 3, 1}};
  REQUIRE(solution(data.at(0)) == 3);
}
