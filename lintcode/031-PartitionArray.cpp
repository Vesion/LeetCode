#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        int n = nums.size();
        int p = 0;
        for (int i = 0; i < n; ++i)
            if (nums[i] < k) swap(nums[p++], nums[i]);
        return p;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 2, 1};
    cout << s.partitionArray(nums, 1) << endl;
    return 0;
}
