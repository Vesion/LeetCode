#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int k = 2;
        for (int i = 2; i < n; ++i) {
            if (nums[i] != nums[k-2]) nums[k++] = nums[i];
        }
        if (k < n) nums.erase(nums.begin() + k, nums.end());
        return k;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-8,0,1,2,3};
    cout << s.removeDuplicates(nums) << endl;
    for (auto i : nums) cout << i << " "; cout << endl;
    return 0;
}
