#include <bits/stdc++.h>

int main() {
  /* Increases input efficiency. */
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  /* freopen("test_input.txt", "r", stdin); //For testing */

  long n, num = 0L;
  long sum = 0L;
  std::vector<long> numbers;
  std::cin >> n;
  while (std::cin >> num) {
    numbers.push_back(num);
  }

  // Logic to print the missing number.
  long expected_sum = (n * (n + 1L)) / 2L;
  sum = std::accumulate(begin(numbers), end(numbers), 0L);
  auto result = (expected_sum - sum);
  std::cout << result << "\n";
}
