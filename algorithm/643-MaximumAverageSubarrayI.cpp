#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  double findMaxAverage(vector<int>& nums, int k) { 
    int i = 0, j = 0;
    double sum = 0, res = INT_MIN;
    while (j < (int)nums.size()) {
      sum += nums[j++];
      if (j-i == k) {
        res = max(res, sum/k);
        sum -= nums[i++];
      }
    }
    return res;
  }  
};


int main() {
  return 0;
}
