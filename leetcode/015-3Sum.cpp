#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        const int n = nums.size();
        if (n < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < n-2; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            const int t = -nums[i];
            int j = i+1, k = n-1;
            while (j < k) {
                const int s = nums[j] + nums[k];
                if (s == t) {
                    res.push_back({nums[i], nums[j++], nums[k--]});
                    while (j < k && nums[j] == nums[j-1]) ++j;
                    while (j < k && nums[k] == nums[k+1]) --k;
                }
                else if (s < t) ++j;
                else --k;
            }
        }
        return res;
    }
};

int main() {
    return 0;
}
