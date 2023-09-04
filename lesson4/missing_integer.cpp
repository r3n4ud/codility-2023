#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <numeric>
#include <random>

#include <algorithm>
#include <set>
#include <vector>

int solution(std::vector<int>& A) {
  int result = 1;

  std::set<int> s(std::begin(A), std::end(A));
  auto first_pos = std::find_if(s.begin(), s.end(), [](int c) { return c > 0; });
  if (first_pos != s.end()) {
    s.erase(s.begin(), first_pos);
  }

  if (!s.empty()) {
    if (s.size() == 1) {
      if (*s.begin() == 1) result = 2;
    } else {
      if (*s.begin() <= 1) {
        auto it =
            std::adjacent_find(s.begin(), s.end(), [](auto l, auto r) { return (l + 1 != r); });
        if (it == s.end()) {
          int last_val = *s.rbegin();
          if (last_val > 0) result = last_val + 1;
        } else {
          if (*it > 0) {
            result = *it + 1;
          }
        }
      }
    }
  }
  return result;
}

TEST_CASE("Lesson 4 Counting Elements / MissingInteger", "[counting-elements]") {
  std::vector<std::vector<int>> data{{1, 3, 6, 4, 1, 2}, {1, 2, 3},          {-1, -3}, {1}, {2},
                                     {4, 5, 6, 2},       {-1000000, 1000000}};

  auto rng = std::default_random_engine{};

  std::vector<int> data_large(200);
  std::iota(data_large.begin(), data_large.end(), 0);
  data_large.erase(std::find(data_large.begin(), data_large.end(), 101));
  std::shuffle(std::begin(data_large), std::end(data_large), rng);

  std::vector<int> data_xl(10005);
  std::iota(data_xl.begin(), data_xl.end(), -4000);
  data_xl.erase(std::find(data_xl.begin(), data_xl.end(), 111));
  std::shuffle(std::begin(data_xl), std::end(data_xl), rng);

  REQUIRE(solution(data.at(0)) == 5);
  REQUIRE(solution(data.at(1)) == 4);
  REQUIRE(solution(data.at(2)) == 1);
  REQUIRE(solution(data.at(3)) == 2);
  REQUIRE(solution(data.at(4)) == 1);
  REQUIRE(solution(data.at(5)) == 1);
  REQUIRE(solution(data.at(6)) == 1);
  REQUIRE(solution(data_large) == 101);
  REQUIRE(solution(data_xl) == 111);
}
