#include <catch2/catch_test_macros.hpp>

int solution(int X, int Y, int D) {
  int result = 0;
  if (X >= 1 && Y >= 1 && D >= 1) {
    int path_length = Y - X;
    if (path_length > 0) {
      result = static_cast<int>(path_length / D);
      if (path_length % D > 0) result++;
    }
  }
  return result;
}

TEST_CASE("Lesson 3 Time Complexity / FrogJmp", "[timecomplexity]") {
  REQUIRE(solution(10, 85, 30) == 3);
  REQUIRE(solution(0, 85, 30) == 0);
  REQUIRE(solution(90, 85, 30) == 0);
  REQUIRE(solution(0, 100, 10) == 0);
  REQUIRE(solution(1, 101, 10) == 10);
  REQUIRE(solution(1, 101, 5) == 20);
  REQUIRE(solution(45, 73, 10) == 3);
}
