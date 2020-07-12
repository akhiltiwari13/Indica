#include <bits/stdc++.h>

int main() {
  /* Increases input efficiency. */
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  /* freopen("test_input.txt", "r", stdin); //For testing */

  int n = 0;
  long num = 0L;
  std::vector<long> numbers;

  std::cin >> n;
  while (std::cin >> num) {
    numbers.push_back(num);
  }

  // Logic to print the increasing array.
  /* long max_thus_far = std::numeric_limits<long>::min; */
  long max_thus_far = numbers[0];
  long increment_count = 0;

  for (auto e : numbers) {
    if (e < max_thus_far) {
      increment_count += (max_thus_far - e);
    } else if (e > max_thus_far)
      max_thus_far = e;
  }

  std::cout << increment_count << "\n";
}
