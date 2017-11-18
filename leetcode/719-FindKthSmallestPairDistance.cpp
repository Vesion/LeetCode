#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
using namespace std;

// Similar to 378. and 668.
// Heap or Binary search


// Solution 1 : heap, O(klogk), TLE
class Solution_1 {
public:
  int smallestDistancePair(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    k = n*(n-1)/2-k+1;
    priority_queue<pair<int,int>> pq;
    pq.push({nums[n-1]-nums[0], n-1});
    int res = 0;
    while (!pq.empty() && k--) {
      auto p = pq.top(); pq.pop();
      res = p.first;
      int i = p.second/n, j = p.second%n;
      if (j-1 >= 0) pq.push({nums[j-1]-nums[i], i*n+(j-1)});
      if (j == n-1 && i+1 < n) pq.push({nums[j]-nums[i+1], (i+1)*n+j});
    }
    return res;
  }
};


// Solution 2 : Binary search, O(nlogN), N is search range from smallest number to largest one
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      int left = 0, right = nums[n-1];
      while (left <= right) {
        int mid = left + (right-left)/2;
        int cnt = 0, j = 0;
        for (int i = 0; i < n; ++i) {
          while (j < n && nums[j]-nums[i] <= mid) ++j;
          cnt += j-i-1;
        }
        if (cnt < k) left = mid+1;
        else right = mid-1;
      }
      return left;
    }
};


int main() {
  Solution s;
  vector<int> nums = {1,3,1};
  cout << s.smallestDistancePair(nums, 3) << endl;
  return 0;
}
