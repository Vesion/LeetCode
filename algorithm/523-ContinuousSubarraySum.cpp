#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

// Solution 1 : brute-force, O(n^2)
class Solution_1 {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;
        if (k == 0) {
            for (int i = 1; i < n; ++i) if (nums[i] == 0 && nums[i-1] == 0) return true;
            return false;
        }
        for (int i = 0; i < n-1; ++i) {
            int sum = nums[i];
            for (int j = i+1; j < n; ++j) {
                sum += nums[j];
                if (sum % k == 0) return true;
            }
        }
        return false;
    }
};


// Solution 2 : hash table, O(n)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) return false;
        if (k == 0) {
            for (int i = 1; i < n; ++i) if (nums[i] == 0 && nums[i-1] == 0) return true;
            return false;
        }
        k = abs(k);
        unordered_map<int, int> sums;
        sums[0] = -1;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum = (sum + nums[i]) % k; // think about it
            if (sums.count(sum) && sums[sum] < i-1) return true;
            sums.insert({sum, i});
        }
        return false;
    }
};


int main() {
    Solution s;
    vector<int> nums = {0, 0};
    cout << s.checkSubarraySum(nums, 1) << endl;
    return 0;
}
