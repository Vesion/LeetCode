#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res = 0;
        map<int,int> m;
        for (int i = 0, j = 0; j < nums.size(); ++j) {
            m[nums[j]]++;
            while (m.rbegin()->first - m.begin()->first > limit) {
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
