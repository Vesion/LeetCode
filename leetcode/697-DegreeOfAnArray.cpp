#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  const int MAXN = 50000;
  vector<int> c, p;

  int findShortestSubArray(vector<int>& nums) {
    int n = nums.size();
    c.resize(MAXN, 0);
    p.resize(MAXN, -1);
    int d = 0;
    for (int& num : nums) d = max(d, ++c[num]);
    int res = n;
    for (int i = 0; i < MAXN; ++i) c[i] = 0;
    for (int i = 0; i < n; ++i) {
      if (p[nums[i]] == -1) p[nums[i]] = i;
      if (++c[nums[i]] == d) res = min(res, i-p[nums[i]]+1);
    }
    return res;
  }
};


int main() {
  Solution s;
  vector<int> nums = {1, 2, 2, 3, 1};
  cout << s.findShortestSubArray(nums) << endl;
  return 0;
}
