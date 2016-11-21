#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set> 
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for (int num : nums) {
            int left = num-1, right = num+1;
            while (s.count(left)) s.erase(left--);
            while (s.count(right)) s.erase(right++);
            res = max(res, right-left-1);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {100, 200, 1, 10, 2, 4, 3};
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}

