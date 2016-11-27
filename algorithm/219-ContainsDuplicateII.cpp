#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (m.count(nums[i])) {
                if (i-m[nums[i]] <= k) return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};

int main() {
    Solution s;
    return 0;
}

