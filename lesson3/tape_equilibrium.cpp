#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <cmath>
#include <numeric>
#include <set>
#include <vector>

int solution(std::vector<int>& A) {
  int size = A.size();
  std::vector<int> sum(size - 1, 0);
  std::vector<int> rsum(size - 1, 0);
  std::partial_sum(A.cbegin(), A.cend() - 1, sum.begin());
  std::partial_sum(A.crbegin(), A.crend() - 1, rsum.begin());
  std::transform(sum.begin(), sum.end(), rsum.rbegin(), sum.begin(),
                 [](int l, int r) { return std::abs(l - r); });
  std::set<int> diffs(std::make_move_iterator(sum.begin()), std::make_move_iterator(sum.end()));

  //// Second attempt
  // std::set<int> diffs;
  // for (int i = 1; i < size; ++i) {
  //   int left = 0;
  //   int right = 0;
  //   for (int j = 0; j < i; ++j) left = left + A.at(j);
  //   for (int k = i; k < size; ++k) right = right + A.at(k);
  //   diffs.insert(std::abs(left - right));
  // }

  //// First attempt
  // std::set<int> diffs;
  // for (auto it = A.begin(); it != A.end() - 1; ++it) {
  // int left = std::accumulate(A.begin(), it + 1, 0.0f);
  // int right = std::accumulate(it + 1, A.end(), 0.0f);
  //   diffs.insert(std::abs(left - right));
  // }
  return *diffs.begin();
}

TEST_CASE("Lesson 3 Time Complexity / TapeEquilibrium", "[timecomplexity]") {
  std::vector<std::vector<int>> data{{3, 1, 2, 4, 3}, {1, 2}};
  REQUIRE(solution(data.at(0)) == 1);
  REQUIRE(solution(data.at(1)) == 1);
}
