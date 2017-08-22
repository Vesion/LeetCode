#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        auto lb = lower_bound(nums.begin(), nums.end(), target);
        if (lb == nums.end() || *lb != target) return {-1, -1};
        auto ub = upper_bound(nums.begin(), nums.end(), target);
        return {int(lb-nums.begin()), int(ub-nums.begin()-1)};
    } 
};

int main() {
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    auto r = s.searchRange(nums, 10);
    cout << r[0] << " " << r[1] << endl;
    return 0;
}
