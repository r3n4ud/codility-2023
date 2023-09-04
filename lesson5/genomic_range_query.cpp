#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <map>
#include <string>
#include <vector>

std::vector<int> solution(std::string& S, std::vector<int>& P, std::vector<int>& Q) {
  int q_size = P.size();
  std::vector<int> total_impacts_list(q_size);

  std::map<char, int> impact_factors{{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};

  if (q_size == Q.size()) {
    for (int i = 0; i < q_size; ++i) {
      if (P.at(i) <= Q.at(i)) {
        auto it = std::min_element(S.begin() + P.at(i), S.begin() + Q.at(i) + 1);
        total_impacts_list.at(i) = impact_factors.at(*it);
      }
    }
  }
  return total_impacts_list;
}

TEST_CASE("Lesson 5 Prefix Sums / GenomicRangeQuery", "[prefix-sums]") {
  std::vector<std::string> data{{"CAGCCTA"}, {"A"}, {"AC"}};
  std::vector<std::vector<int>> p{{2, 5, 0}, {0}, {0, 0, 1}};
  std::vector<std::vector<int>> q{{4, 5, 6}, {0}, {0, 1, 1}};
  REQUIRE(solution(data.at(0), p.at(0), q.at(0)) == std::vector<int>{2, 4, 1});
  REQUIRE(solution(data.at(1), p.at(1), q.at(1)) == std::vector<int>{1});
  REQUIRE(solution(data.at(2), p.at(2), q.at(2)) == std::vector<int>{1, 1, 2});
}
