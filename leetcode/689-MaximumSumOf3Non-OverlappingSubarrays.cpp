#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Similar to 123-BestTimeToBuyAndSellStockIII
// Pre-calculate left-preifx and right-suffix max sum subarray with size k
class Solution {
public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    if (n < 3) return {};
    int s = 0;
    vector<pair<int,int>> left(n, {-1, -1});
    for (int i = 0; i < n; ++i) {
      s += nums[i];
      if (i >= k-1) {
        if (i >= k) s -= nums[i-k];
        if (i == 0 || s > left[i-1].first) left[i] = {s, i-k+1};
        else left[i] = left[i-1];
      }
    }

    vector<pair<int,int>> right(n, {-1,-1});
    s = 0;
    for (int i = n-1; i >= 0; --i) {
      s += nums[i];
      if (n-i >= k) {
        if (n-i > k) s -= nums[i+k];
        if (i == n-1 || s > right[i+1].first) right[i] = {s, i};
        else right[i] = right[i+1];
      }
    }

    s = 0;
    for (int i = k; i < 2*k; ++i) s += nums[i];
    int maxs = left[k-1].first + s + right[2*k].first;
    int mid = 2*k-1;
    for (int i = 2*k; i < n-k; ++i) {
      s = s + nums[i] - nums[i-k];
      int t = left[i-k].first + s + right[i+1].first;
      if (t > maxs) {
        maxs = t;
        mid = i;
      }
    }
    return {left[mid-k].second, mid-k+1, right[mid+1].second};
  }
};


int main() {
  Solution s;
  vector<int> nums = { 17,7,19,11,1,19,17,6,13,18,2,7,12,16,16,18,9,3,19,5 };
  auto r = s.maxSumOfThreeSubarrays(nums, 6);
  for (auto& e : r) cout << e << " "; cout << endl; 
  return 0;
}
