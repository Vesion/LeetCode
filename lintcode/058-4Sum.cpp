#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;
        if (n < 4) return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-3; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < n-2; ++j) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                int k = j+1, l = n-1;
                int sum = target-nums[i]-nums[j];
                while (k < l) {
                    if (nums[k]+nums[l] == sum) {
                        result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        ++k, --l;
                        while (k < l && nums[k] == nums[k-1]) ++k;
                        while (k < l && nums[l] == nums[l+1]) --l;
                    }
                    else if (nums[k]+nums[l] < sum) ++k;
                    else --l;
                }
            }
        }
        return result;
    } 
};

int main() {
    Solution s;
    vector<int> nums = {-1, -1, -1, -1, 0, 0, 1, 1, 1, 1, 2};
    auto r = s.fourSum(nums, 2);
    for (auto i : r) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
