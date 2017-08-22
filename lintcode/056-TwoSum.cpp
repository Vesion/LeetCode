#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (m.count(nums[i])) return { m[nums[i]]+1, i+1 };
            m[target-nums[i]] = i;
        }
        return {-1, -1}; // never
    }
};


int main() {
    Solution s;
    vector<int> nums = {4, 5, 6, 1, 232, 0, 2};
    auto r = s.twoSum(nums, 3);
    cout << r[0] << " " << r[1] << endl;
    return 0;
}
