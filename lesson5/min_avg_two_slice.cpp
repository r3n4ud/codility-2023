#include <catch2/catch_test_macros.hpp>

#include <iostream>

#include <algorithm>
#include <functional>
#include <map>
#include <numeric>
#include <vector>

int solution(std::vector<int>& A) {
  int pos = 0;
  int n = A.size();
  std::map<int, double> smallest_avg_by_pos;

  for (int p = 0; p < n - 1; ++p) {
    std::vector<int> v(n - p);
    std::partial_sum(A.begin() + p, A.end(), v.begin());
    std::vector<int> div(n - p);
    std::iota(div.begin(), div.end(), 1);
    std::vector<double> result(n - p - 1);

    std::transform(v.begin() + 1, v.end(), div.begin() + 1, result.begin(), std::divides<double>());
    smallest_avg_by_pos[p] = *std::min_element(result.begin(), result.end());
  }

  pos =
      std::min_element(smallest_avg_by_pos.begin(), smallest_avg_by_pos.end(), [](auto l, auto r) {
        return l.second < r.second;
      })->first;

  // for (auto& [k, v] : smallest_avg_by_pos) {
  //   std::cout << "k " << k << ", v " << v << std::endl;
  // }
  return pos;
}

TEST_CASE("Lesson 5 Prefix Sums / ManAvgTwoSlice", "[prefix-sums]") {
  std::vector<std::vector<int>> data{{4, 2, 2, 5, 1, 5, 8}};
  REQUIRE(solution(data.at(0)) == 1);
}
