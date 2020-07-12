#include <bits/stdc++.h>

int main() {
  /* Increases input efficiency. */
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  /* freopen("test_input.txt", "r", stdin); //For testing */

  std::string dna_sequence;
  std::cin >> dna_sequence;

  // Logic to print the largest repetiton in a DNA Sequence.
  char previous_character = dna_sequence[0];
  int local_max_len = 0;
  int global_max_len = 0;
  for (auto c : dna_sequence) {
    if (c == previous_character) {
      ++local_max_len;
      global_max_len = std::max(global_max_len, local_max_len);
    } else {
      local_max_len = 1;
      previous_character = c;
    }
  }
  std::cout << global_max_len << std::endl;
}
