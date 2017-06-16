#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : binary search, O(n^2*logn)
class Solution_1 {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            for (int j = i-1; j >= 0; --j) res += j-(upper_bound(nums.begin(), nums.begin()+j, nums[i]-nums[j])-nums.begin());
        }
        return res;
    }
};


// Solution 2 : two pointers, O(n^2)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            int l = 0, r = i-1;
            while (l < r) {
                if (nums[l]+nums[r] > nums[i]) {
                    res += r-l;
                    --r;
                } else ++l;
            }
        }
        return res;
    }
};


int main() {
    return 0;
}
