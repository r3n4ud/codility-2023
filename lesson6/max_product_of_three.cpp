#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <set>
#include <vector>

int solution(std::vector<int>& A) {
  int max_product = -1000000001;
  for (auto i = A.begin(); i != std::prev(A.end(), 2); ++i) {
    for (auto j = std::next(i, 1); j != std::prev(A.end(), 1); ++j) {
      std::vector<int> v(std::next(j, 1), A.end());
      std::transform(v.begin(), v.end(), v.begin(), [i, j](auto elt) { return *i * *j * elt; });
      int max_local = *std::max_element(v.begin(), v.end());
      if (max_local > max_product) max_product = max_local;
    }
  }
  return max_product;
}

TEST_CASE("Lesson 6 Sorting / MaxProductOfThree", "[sorting]") {
  std::vector<std::vector<int>> data{{-3, 1, 2, -2, 5, 6}, {-10, -2, -4}};
  REQUIRE(solution(data.at(0)) == 60);
  REQUIRE(solution(data.at(1)) == -80);
}
