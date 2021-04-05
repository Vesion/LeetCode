#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i = 0, j = 1, n = nums.size();
        for (; j <= n; ++j) {
            if (j == n || nums[j] > nums[j-1]+1) {
                if (j-1 > i)
                    res.push_back(to_string(nums[i]) + "->" + to_string(nums[j-1]));
                else
                    res.push_back(to_string(nums[i]));
                i = j;
            }
        }
        return res;
    }
};


int main() {
    return 0;
}
