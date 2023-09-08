#include <catch2/catch_test_macros.hpp>

#include <vector>

int solution(std::vector<int>& A) {
  int eastbound_cars = 0;
  int passing_cars = 0;

  for (int i = 0; i < A.size(); i++) {
    if (A[i] == 0) {
      eastbound_cars++;
    } else {
      passing_cars += eastbound_cars;
      if (passing_cars > 1000000000) {
        return -1;
      }
    }
  }

  return passing_cars;
}

TEST_CASE("Lesson 5 Prefix Sums / PassingCars", "[prefix-sums]") {
  std::vector<std::vector<int>> data{{0, 1, 0, 1, 1}};
  REQUIRE(solution(data.at(0)) == 5);
}
