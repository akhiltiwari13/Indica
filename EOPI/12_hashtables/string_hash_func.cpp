/**
 * File              : string_hash_func.cpp
 * Author            : akhil <akhiltiwari.13@gmail.com>
 * Date              : 06.06.2021
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>

int stringHash(const std::string &str, int bucketLen) {
  int multiplier = 3;
  return std::accumulate(std::cbegin(str), std::cend(str), 0,
                         [multiplier, bucketLen](int val, const char c) -> int {
                           return ((val * multiplier) + c) % bucketLen;
                         });
}

int main() {
  std::string str{"akhil"};

  do {
    std::cout << "hash of " << str
              << " for bucket lenght 7= " << stringHash(str, 7) << std::endl;
  } while (std::next_permutation(begin(str), end(str)));

  return 0;
}

