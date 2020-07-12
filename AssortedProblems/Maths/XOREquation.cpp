#include <bits/stdc++.h>

using namespace std;

vector<long long> equationSol(long long x, long long y) {
  // Write your code here
  vector<long long> result;
  long long lim = 0;
  if (x % 2 == 0) {
    lim = x / 2;
  } else {
    lim = x / 2 + 1;
  }

  for (long long a = 0LL, b = x; a <= lim; ++a, --b) {
    if ((a ^ b) == y) {
      result.push_back(a);
      result.push_back(b);
    }
    break;
  }

  if (result.empty()) {
    result.push_back(-1LL);
  }

  return result;
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  for (int t_i = 0; t_i < T; t_i++) {
    long long x;
    cin >> x;
    long long y;
    cin >> y;

    vector<long long> out_;
    out_ = equationSol(x, y);
    cout << out_[0];
    if (out_[0] != -1)
      cout << " " << out_[1];
    cout << "\n";
  }
}
