#include <bits/stdc++.h>

unsigned long long get_element(unsigned long long y, unsigned long long x) {
  unsigned long long result = 0llu;
  if (y % 2llu == 0llu) {
    result = (y * y) - x + 1llu;
  } else {
    result = (x * x) - y + 1llu;
  }
  return result;
}

int main() {
  /* Increases input efficiency. */
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  /* freopen("test_input.txt", "r", stdin); //For testing */

  int test_case_count = 0;
  unsigned long long row_y = 0llu;
  unsigned long long col_x = 0llu;

  std::vector<std::pair<unsigned long long, unsigned long long>> test_cases;

  std::cin >> test_case_count;
  while (test_case_count--) {
    std::cin >> row_y >> col_x;
    test_cases.push_back({row_y, col_x});
  }

  for (auto test : test_cases) {
    std::cout << get_element(test.first, test.second) << std::endl;
  }
  return 0;
}
