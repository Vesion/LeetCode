#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> sums;
        sums.insert({0, -1});
        int res = 0;
        int sum = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            sum += nums[i];
            int t = sum - k;
            if (sums.count(t)) res = max(res, i-sums[t]);
            sums.insert({sum, i}); // here cannot use sums[sum] = i, think about it
        }
        return res;
    }
};


int main() {
    return 0;
}
