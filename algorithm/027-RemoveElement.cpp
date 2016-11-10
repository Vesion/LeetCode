#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Solution 1 : use std::remove
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        return distance(nums.begin(), remove(nums.begin(), nums.end(), val));
    }
};

// Solution 2
class Solution_2 {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        int i = 0;
        for (int j = 0; j < (int)nums.size(); ++j) {
            if (nums[j] != val)
                nums[i++] = nums[j];
        }
        nums.erase(nums.begin()+i, nums.end());
        return i;
    }
};


int main() {
    return 0;
}
