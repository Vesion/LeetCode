#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1;
        vector<int> res(n); int k = n-1;
        while (k >= 0) {
            if (abs(nums[i]) > abs(nums[j])) {
                res[k--] = nums[i] * nums[i];
                ++i;
            } else {
                res[k--] = nums[j] * nums[j];
                --j;
            }
        }
        return res;
    }
};

int main() {

}