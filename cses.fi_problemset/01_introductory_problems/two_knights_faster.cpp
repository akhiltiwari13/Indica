#include <bits/stdc++.h>

unsigned int solve_two_knights(unsigned int n) {
  uint result = 0;
  for (uint i = 3; i <= n; ++i) {
    result = result + 2 * (i - 1) * (i - 1) * (i - 2);
  }
  return result;
}

int main() {
  /* Increases input efficiency. */
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  /* freopen("test_input.txt", "r", stdin); //For testing */

  unsigned int matrix_size = 0u;
  std::cin >> matrix_size;

  for (unsigned int i = 1; i <= matrix_size; ++i) {
    std::cout << solve_two_knights(i) << std::endl;
  }

  return 0;
}
