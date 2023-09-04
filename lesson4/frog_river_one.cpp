#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <set>
#include <vector>

int solution(int X, std::vector<int>& A) {
  int result = -1;
  std::vector<int>::iterator target_pos_it = std::find(A.begin(), A.end(), X);

  if (target_pos_it != A.end()) {
    std::set<int> s(A.begin(), target_pos_it + 1);
    if (s.size() == X) {
      result = std::distance(A.begin(), target_pos_it);
    } else {
      while (++target_pos_it != A.end()) {
        s.insert(*target_pos_it);
        if (s.size() == X) {
          result = std::distance(A.begin(), target_pos_it);
          break;
        }
      }
    }
  }
  return result;
}

TEST_CASE("Lesson 4 Counting Elements / FrogRiverOne", "[counting-elements]") {
  std::vector<std::vector<int>> data{
      {1, 3, 1, 4, 2, 3, 5, 4},
      {1, 3, 1, 3, 2, 1, 3},
      {3},
  };
  REQUIRE(solution(5, data.at(0)) == 6);
  REQUIRE(solution(3, data.at(1)) == 4);
  REQUIRE(solution(5, data.at(2)) == -1);
}
