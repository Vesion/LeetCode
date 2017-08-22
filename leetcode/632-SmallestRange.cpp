#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue> 
#include <deque> 
using namespace std;

// Similar to merge k sorted array
class Solution {
public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    int k = nums.size();

    auto cmp = [&nums](const pair<int,int>& p1, const pair<int,int>& p2) {
      return nums[p1.first][p1.second] > nums[p2.first][p2.second];
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> pq(cmp);
    int max_num = INT_MIN, min_len = INT_MAX;
    for (int i = 0; i < k; ++i) {
      max_num = max(max_num, nums[i][0]);
      pq.push({i, 0});
    }

    vector<int> res = {0, INT_MAX};
    while ((int)pq.size() == k) {
      auto i = pq.top().first, j = pq.top().second; pq.pop();
      if (max_num - nums[i][j] < min_len) {
        min_len = max_num - nums[i][j];
        res[0] = nums[i][j];
        res[1] = max_num;
      }
      if (j < (int)nums[i].size()-1) {
        max_num = max(max_num, nums[i][j+1]);
        pq.push({i, j+1});
      }
    }
    return res;
  }
};


int main() {
  Solution s;
  vector<vector<int>> nums = {
    { 4,10,15,24,26 },
    { 0,9,12,20 },
    { 5,18,22,30 }
  };
  auto r = s.smallestRange(nums);
  cout << r[0] << " " << r[1] << endl;
  return 0;
}
