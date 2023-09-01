#include <catch2/catch_test_macros.hpp>

#include <algorithm>
#include <bitset>
#include <set>

int solution(int N) {
  std::bitset<32> bs(N);
  std::set<int> zeros;
  int zcount = 0;
  bool counting = false;

  for (std::size_t idx = 0; idx < bs.size() - 1; ++idx) {
    if (counting) {
      zcount++;
      if (!bs.test(idx) && bs.test(idx + 1)) {
        zeros.insert(zcount);
        zcount = 0;
        counting = false;
      }
    } else if (bs.test(idx) && !bs.test(idx + 1)) {
      counting = true;
    }
  }

  int result = 0;
  if (!zeros.empty()) {
    result = *zeros.rbegin();
  }

  return result;
}

TEST_CASE("Lesson 1 Iterations / BinaryGap", "[iterations]") {
  REQUIRE(solution(9) == 2);
  REQUIRE(solution(529) == 4);
  REQUIRE(solution(20) == 1);
  REQUIRE(solution(15) == 0);
  REQUIRE(solution(32) == 0);
}
