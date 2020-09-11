#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : std::unique
class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it = unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());
        return it-nums.begin();
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int l = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i-1]) nums[l++] = nums[i];
        }
        return l;
    }
};

int main() {
    return 0;
}
