#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if (nums.empty()) return {getRange(lower, upper)};
        vector<string> res;
        int n = nums.size();

        if (nums[0] > lower) res.push_back(getRange(lower, nums[0]-1));
        for (int i = 1; i < n; ++i)
            if ((long long)nums[i-1]+1 < nums[i]) // convert it to long long, in case overflow after +1
                res.push_back(getRange(nums[i-1]+1, nums[i]-1));
        if (upper > nums[n-1]) res.push_back(getRange(nums[n-1]+1, upper));

        return res;
    }

    string getRange(int left, int right) {
        if (left == right) return to_string(left);
        return to_string(left) + "->" + to_string(right);
    }
};


int main() {
    Solution s;
    vector<int>nums = { INT_MIN, INT_MIN, 0, INT_MAX, INT_MAX };
    auto r = s.findMissingRanges(nums, INT_MIN, INT_MAX);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}

