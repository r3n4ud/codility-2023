#include <catch2/catch_test_macros.hpp>

#include <cmath>

int solution(int A, int B, int K) {
  int count = 0;
  if (A <= B) {
    if (K > 0) {
      if (A % K == 0) {
        count = std::floor((B - A) / K) + 1;
      } else {
        count = std::floor((B - (A - A % K)) / K);
      }
    }
  }
  return count;
}

TEST_CASE("Lesson 5 Prefix Sums / CountDiv", "[prefix-sums]") {
  REQUIRE(solution(6, 11, 2) == 3);
  REQUIRE(solution(6, 11, 0) == 0);
  REQUIRE(solution(10, 5, 2) == 0);
  // REQUIRE(solution(0, 2000000000, 1) == 2000000001);
  // REQUIRE(solution(2, 2, 2) == 1);
  // REQUIRE(solution(1, 1000, 2) == 500);
}
