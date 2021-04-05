#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int pathSum(vector<int>& nums) {
        int tree[6][10] = {};
        bool has[6][10] = {};
        for (int num : nums) {
            int i = num/100, j = (num/10)%10, x = num%10;
            tree[i][j] = x;
            has[i][j] = true;
        }
        int res = 0;
        for (int i = 5; i >= 1; --i) {
            for (int j = 8; j >= 1; --j) {
                if (!has[i][j]) continue;
                for (int p = i, q = j; p >= 1; --p, q = (q+1)/2) {
                    res += tree[p][q];
                    has[p][q] = false;
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
