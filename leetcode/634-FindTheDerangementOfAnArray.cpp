#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  using ll = long long;
  const int MOD = 1e9+7;

  int findDerangement(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    ll r1 = 0, r2 = 1;
    for (int i = 3; i <= n; ++i) {
      ll t = (i-1)*(r1+r2) % MOD;
      r1 = r2;
      r2 = t;
    }
    return r2;
  }
};


int main() {
  return 0;
}
