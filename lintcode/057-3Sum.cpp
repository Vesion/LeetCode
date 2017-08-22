#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> result;
        if (n < 3) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1, k = n-1, sum = 0 - nums[i];
            while (j < k) {
                if (nums[j]+nums[k] == sum) {
                    result.push_back({nums[i],nums[j],nums[k]});
                    ++j, --k;
                    while (j < k && nums[j] == nums[j-1]) ++j;
                    while (j < k && nums[k] == nums[k+1]) --k;
                }
                else if (nums[j]+nums[k] < sum) ++j;
                else --k;
            }
        }
        return result;
    } 
};

int main() {
    Solution s;
    vector<int> nums = {-1,0,1,2,-1,-4};
    auto r = s.threeSum(nums);
    for (auto i : r) {
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}
