#include <catch2/catch_test_macros.hpp>

int solution(int blocks[], int N) {
  int result = 0;

  int dist_max = 0;
  for (int i = 0; i < N; i++) {
    int dist = 0;
    for (int l = i - 1; l >= 0; l--) {
      if (blocks[l] >= blocks[l + 1])
        dist++;
      else
        break;
    }
    for (int r = i + 1; r < N; r++) {
      if (blocks[r] >= blocks[r - 1])
        dist++;
      else
        break;
    }
    if (dist >= dist_max) dist_max = dist;
  }

  return dist_max + 1;
}

TEST_CASE("Task 2", "[tasks]") {
  int data1[4] = {2, 6, 8, 5};
  REQUIRE(solution(data1, 4) == 3);

  int data2[5] = {1, 5, 5, 2, 6};
  REQUIRE(solution(data2, 5) == 4);

  int data3[2] = {1, 1};
  REQUIRE(solution(data3, 2) == 2);
}
