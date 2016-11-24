#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// bucket sort / pigeon hole principle
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        auto it = minmax_element(nums.begin(), nums.end());
        int lower = *it.first, upper = *it.second; // the minimum and maximum number in array

        int gap = max((upper-lower) / (n-1), 1); // bucket size
        int m = (upper-lower)/gap + 1; // m buckets

        vector<int> mins(m, INT_MAX), maxs(m, INT_MIN); // store the minimum and maximum number in each bucket

        for (int num : nums) {
            int k = (num-lower) / gap;
            mins[k] = min(mins[k], num);
            maxs[k] = max(maxs[k], num);
        }

        int res = 0;
        int last_max = lower;
        for (int i = 0; i < m; ++i) {
            if (mins[i] == INT_MAX) continue;
            res = max(res, mins[i] - last_max);
            last_max = maxs[i];
        }
        return res;
    }
};

int main() {
    Solution s;
    return 0;
}

