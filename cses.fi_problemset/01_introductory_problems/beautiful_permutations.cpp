#include <bits/stdc++.h>

int main() {
  /* Increases input efficiency. */
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  /* freopen("test_input.txt", "r", stdin); //For testing */

  int n = 0;
  std::cin >> n;

  /* Logic to print beautiful premutations. */
  /* edge cases. */
  if (n == 2 || n == 3) {
    std::cout << "NO SOLUTION";
    return 0;
  }

  /* print the evens first and then the odds... got this strategy from the
   * websites' test outputs... :-) */
  for (int i = 2; i <= n; i += 2) {
    std::cout << i << " ";
  }
  for (int i = 1; i <= n; i += 2) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}
