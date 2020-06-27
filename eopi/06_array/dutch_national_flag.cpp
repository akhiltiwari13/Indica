#include <bits/stdc++.h>
using namespace std;

void dutch_national_flagging(vector<int> &arr, uint pivot_index) {
  int key = arr[pivot_index];
  for (int i = 0, j = arr.size() - 1; i < j;) {
    if (arr[i] < key) {
      i++;
    } else {
      swap(arr[i], arr[j]);
      --j;
    }
  }
}

int main() {
  vector<int> arr = {2, 3, 4, 6, 13, 3, 8, 12, 23, 6, 9};
  dutch_national_flagging(arr, 4);
  for (auto itr : arr) {
    cout << itr << " ";
  }
  cout << std::endl;
}
