#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// O(nlogn + n^2)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < n-2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1, k = n-1;
            int t = -nums[i];
            while (j < k) {
                int s = nums[j] + nums[k];
                if (s == t) {
                    res.push_back({nums[i], nums[j++], nums[k--]});
                    while (j < k && nums[j] == nums[j-1]) ++j;
                    while (j < k && nums[k] == nums[k+1]) --k;
                } else if (s < t) {
                    ++j;
                } else {
                    --k;
                }
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
