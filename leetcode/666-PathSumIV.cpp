#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int pathSum(vector<int>& nums) {
    vector<vector<int>> tree(5, vector<int>(9, -1));
    for (int& num : nums) {
      int d = num/100, p = (num/10)%10, v = num%10;
      tree[d][p] = v;
    }
    int res = 0;
    for (int i = 1; i <= 4; ++i) {
      for (int j = 1; j <= 8; ++j) {
        if (tree[i][j] != -1) {
          if (i < 4 && tree[i+1][2*j-1] != -1) tree[i+1][2*j-1] += tree[i][j];
          if (i < 4 && tree[i+1][2*j] != -1) tree[i+1][2*j] += tree[i][j];
          if (i == 4 || (tree[i+1][2*j-1] == -1 && tree[i+1][2*j] == -1)) res += tree[i][j];
        }
      }
    }
    return res;
  }
};


int main() {
  Solution s;
  vector<int> nums = { 113,215,221 };
  cout << s.pathSum(nums) << endl;
  return 0;
}
