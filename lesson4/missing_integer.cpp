#include <catch2/catch_test_macros.hpp>

#include <vector>

int solution(std::vector<int>& A) { return 0; }

TEST_CASE("Lesson 4 Counting Elements / MissingInteger", "[counting-elements]") {
  std::vector<std::vector<int>> data{
      {},
  };
  REQUIRE(solution(data.at(0)) == -1);
}
