#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int dominantIndex(vector<int>& nums) {
    int j = 0, n = nums.size();
    for (int i = 0; i < n; ++i) if (nums[i] > nums[j]) j = i;
    for (int i = 0; i < (int)nums.size() ; ++i) if (i != j && nums[i]*2 > nums[j]) return -1;
    return j;
  }
};


int main() {
  return 0;
}
