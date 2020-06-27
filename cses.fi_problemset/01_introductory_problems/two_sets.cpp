#include <bits/stdc++.h>

bool is_2_set_possible(ulong n) {
  if ((n * (n + 1) / 2) % 2)
    return false;
  return true;
}

void form_2_sets(ulong n) {
  std::vector<ulong> group1;
  std::vector<ulong> group2;

  ulong max_sum_possible = (n * (n + 1) / 4);

  for (ulong i = n; i > 0; --i) {
    if (i <= max_sum_possible) {
      group1.push_back(i);
      max_sum_possible -= i;
    } else
      group2.push_back(i);
  }

  std::cout << group1.size() << std::endl;
  for (auto itr : group1)
    std::cout << itr << " ";
  std::cout << std::endl;

  std::cout << group2.size() << std::endl;
  for (auto itr : group2)
    std::cout << itr << " ";
  std::cout << std::endl;
}

int main() {
  /* Increases input efficiency. */
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  /* freopen("test_input.txt", "r", stdin); //For testing */

  ulong num = 0;

  std::cin >> num;
  if (is_2_set_possible(num)) {
    std::cout << "YES" << std::endl;
    form_2_sets(num);
  } else {
    std::cout << "NO" << std::endl;
  }
  return 0;
}
