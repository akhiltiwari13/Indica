#include <bits/stdc++.h>
using namespace std;

void classify_odd_even(vector<int> &arr) {
  for (int i = 0, j = arr.size() - 1; i < j;) {
    if (arr[i] % 2)
      ++i; // odds to the left
    else {
      swap(arr[i], arr[j--]);
      /* --j; */
    }
  }
}

int main() {
  vector<int> arr = {2, 3, 4, 6, 13, 3, 8, 12, 23, 6, 9};
  classify_odd_even(arr);
  for (auto itr : arr) {
    cout << itr << " ";
  }
  cout << std::endl;
}
