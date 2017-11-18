#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    int total = 0;
    for (int& num : nums) total += num;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      if (i > 0) sum += nums[i-1];
      if (sum*2 == total-nums[i]) return i;
    }
    return -1;
  }
};


int main() {
  return 0;
}
