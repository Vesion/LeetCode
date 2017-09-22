#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath> 
using namespace std;

// Backtracking, pick two numbers (combination) each time, compute them into one number, until there is only one number, check if it is 24.
class Solution {
public:
  double a[4];
  const double FMIN = 1e-6;
  bool res;

  void dfs(int n) {
    if (n == 1) {
      if (fabs(a[0]-24) < FMIN) res = true;
      return;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = i+1; j < n; ++j) {
        double p = a[i], t = a[j];
        a[j] = a[n-1];

        a[i] = p+t; dfs(n-1);
        a[i] = p-t; dfs(n-1);
        a[i] = t-p; dfs(n-1);
        a[i] = p*t; dfs(n-1);
        if (fabs(t-0) > FMIN) a[i] = p/t; dfs(n-1);
        if (fabs(p-0) > FMIN) a[i] = t/p; dfs(n-1);

        a[i] = p, a[j] = t;
      }
    }
  }

  bool judgePoint24(vector<int>& nums) {
    for (int i = 0; i < 4; ++i) a[i] = nums[i];
    res = false;
    dfs(4);
    return res;
  }
};


int main() {
  Solution s;
  return 0;
}
