#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

// Solution 1 : bitmap, similar to 136-SingleNumber
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n;
        for (int i = 0; i < n; ++i) {
            res ^= i;
            res ^= nums[i];
        }
        return res;
    }
};


// Solution 2 : counting sort, similar to 041-FirstMissingPositive
class Solution_2 {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] < n && nums[i] != nums[nums[i]])
                swap(nums[nums[i]], nums[i]);
        }
        for (int i = 0; i < n; ++i)
            if (i != nums[i]) return i;
        return n;
    }
};


int main() {
    Solution_2 s;
    vector<int> nums({0});
    cout << s.missingNumber(nums) << endl;
    return 0;
}

