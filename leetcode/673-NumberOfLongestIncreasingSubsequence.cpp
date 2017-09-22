#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    int n = nums.size();
    vector<int> len(n, 1), cnt(n, 1);
    int maxl = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          if (len[i] == len[j]+1) cnt[i] += cnt[j];
          if (len[i] < len[j]+1) {
            len[i] = len[j]+1;
            cnt[i] = cnt[j];
          }
        }
      }
      maxl = max(maxl, len[i]);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) if (len[i] == maxl) res += cnt[i];
    return res;
  }
};


int main() {
  Solution s;
  vector<int> nums = { 1,2,4,3,5,4,7,2 };
  cout << s.findNumberOfLIS(nums) << endl;
  return 0;
}
