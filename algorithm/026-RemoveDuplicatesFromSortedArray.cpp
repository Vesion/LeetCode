#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


// Solution 1 : std::unique
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it = unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());
        return it-nums.begin();
    }
};


// Solution 2
class Solution_2 {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int i = 1;
        for (int j = 1; j < (int)nums.size(); ++j) {
            if (nums[j] != nums[i-1])
                nums[i++] = nums[j];
        }
        nums.erase(nums.begin()+i, nums.end());
        return i;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3,3,3,4};
    cout << s.removeDuplicates(nums) << endl;
    return 0;
}

