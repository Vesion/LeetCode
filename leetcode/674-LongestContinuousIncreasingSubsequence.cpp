#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int findLengthOfLCIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    int res = 1, len = 1;
    for (int i = 1; i < (int)nums.size(); ++i) {
      if (nums[i] > nums[i-1]) res = max(res, ++len);
      else len = 1;
    }
    return res;
  }
};


int main() {
  return 0;
}
