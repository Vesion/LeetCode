#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int,int> m;  // we need a self-maintained ordered container
        int res = 0;
        for (int i = 0, j = 0; j < nums.size() && i <= j; ++j) {
            ++m[nums[j]];
            while (!m.empty()
                   && m.rbegin()->first - m.begin()->first > limit
                   && i <= j) {
                if (--m[nums[i]] == 0) m.erase(nums[i]);
                ++i;
            }
            res = max(res, j-i+1);
        }
        return res;
    }
};

int main() {
    return 0;
}
