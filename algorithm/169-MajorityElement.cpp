#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

// Solution 1 :  Moore Voting Algorithm, O(n) time, O(1) space
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, votes = 0;
        for (int num : nums) {
            if (num == res) ++votes;
            else {
                if (votes == 0) res = num, votes = 1;
                else --votes;
            }
        }
        return res;
    }
};


// Solution 2 : Divide and conquer, O(nlogn) time, O(1) space
class Solution_2 {
public:
    int majorityElement(vector<int>& nums) {
        return majority(nums, 0, nums.size() - 1);
    }

    int majority(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        int mid = left + ((right - left) >> 1);
        int lm = majority(nums, left, mid);
        int rm = majority(nums, mid + 1, right);
        if (lm == rm) return lm;
        return count(nums.begin() + left, nums.begin() + right + 1, lm) > count(nums.begin() + left, nums.begin() + right + 1, rm) ? lm : rm;
    }
};


// Solution 3 : Sort, O(nlogn) time, O(1) space
class Solution_3 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};


// Solution 4 : Hash table, O(n) time, O(n) space
class Solution_4 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m; 
        for (auto & num : nums) {
            ++m[num];
            if (m[num] > (int)nums.size()/2) return num;
        }
        return 0; // never
    }
};


int main() {
    Solution s;
    vector<int> nums = {2,2,1,2,3,2,1,2,4};
    cout << s.majorityElement(nums) << endl;
    return 0;
}

