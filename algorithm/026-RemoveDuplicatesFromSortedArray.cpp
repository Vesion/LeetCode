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
        int r = 1;
        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] != nums[r-1]) nums[r++] = nums[i];
        }
        return r;
    }
};


int main() {
    return 0;
}
