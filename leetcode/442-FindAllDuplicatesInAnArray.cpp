#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : counting sort
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
        }

        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i+1) res.push_back(nums[i]);
        }
        return res;
    }
};


// Solution 2 : flip to negative
class Solution_2 {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < (int)nums.size(); ++i) {
            int id = abs(nums[i]) - 1;
            if (nums[id] < 0) res.push_back(abs(id+1));
            nums[id] = -nums[id];
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    auto r = s.findDuplicates(nums);
    for (auto& e : r) cout << e << " "; cout << endl; 
    return 0;
}

