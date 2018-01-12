#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// math
// https://leetcode.com/problems/reach-a-number/description/
class Solution {
public:
  int reachNumber(int target) {
    target = abs(target);
    int i = 1, sum = 0;
    while (sum < target || (sum-target)%2 == 1) {
      sum += i;
      i++;
    }
    return i-1;
  }
};


int main() {
  Solution s;
  cout << s.reachNumber(13) << endl;
  return 0;
}
