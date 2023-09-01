#include <catch2/catch_test_macros.hpp>

#include <vector>

int solution(std::vector<int>& A) { return 0; }

TEST_CASE("Lesson 3 Time Complexity / TapeEquilibrium", "[timecomplexity]") {
  std::vector<std::vector<int>> data{{3, 1, 2, 4, 3}};
  REQUIRE(solution(data.at(0)) == 1);
}
