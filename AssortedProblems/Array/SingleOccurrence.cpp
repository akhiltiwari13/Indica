/* In an array where all the elements but one occur n number of times and the
 * sole element occurs once, find the sole element. */

#include <bits/stdc++.h>
#define REP(a, b) for (int i = a; i < b; i++)

using namespace std;

int get_single_element_via_bit_manipulation(vector<int> arr, int frequency) {
  int set_bit_count = 0;
  int size = arr.size();
  int result = 0;
  REP(0, 32) {
    set_bit_count = 0;
    REP(0, size) {
      if (arr[i] & 1) {
        set_bit_count++;
      }
      arr[i] = arr[i] >> 1;
    }
    set_bit_count %= frequency;
    set_bit_count = set_bit_count << i;
    result = result | set_bit_count;
  }
  return result;
}

int get_single_element(vector<int> arr, int mod) {
  int size = arr.size();
  int num = 0;
  // using this bit set to convert each integer to it's equivalent binary.
  bitset<32> bit_set;
  vector<int> count_bit(32, 0);
  REP(0, size) {
    bit_set = arr[i];
    for (int j = 0; j < 32; j++) {
      if (bit_set[j]) {
        count_bit[j]++;
      }
    }
  }

  // taking the modulo by repetitions.
  REP(0, 32) {
    count_bit[i] %= mod;
    num = num + count_bit[i] * pow(2, i);
  }
  return num;
}

// using the more intuitve approach of using a map.
int get_single_element_map(vector<int> arr, int mod) {
  unordered_map<int, int> arr_count;
  int size = arr.size();
  // maintainig the count of the occurance of each element in an array.
  REP(0, size) { arr_count[arr[i]]++; }
  for (auto itr : arr_count) {
    if (itr.second == 1) {
      return itr.first;
    }
  }
  return 0;
}

int main(void) {
  vector<int> arr = {5, 5, 4, 8, 4, 5, 8, 9, 4, 8};
  int mod = 3;
  int res = get_single_element(arr, mod);
  cout << "the number that occurs only once is: " << res << endl;
  res = get_single_element_map(arr, mod);
  cout << "the number that occurs only once using a hash map approach, is: "
       << res << endl;
  res = get_single_element_via_bit_manipulation(arr, mod);
  cout << "the number that occurs only once using bit manipulation approach, "
          "is: "
       << res << endl;

  return 0;
}
