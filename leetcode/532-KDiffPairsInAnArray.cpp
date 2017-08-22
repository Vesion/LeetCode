#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map> 
using namespace std;

// Solution 1 : sort and binary search, O(nlogn), O(1)
class Solution_1 {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n-1; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue; // avoid duplicates
            if (binary_search(nums.begin()+i+1, nums.end(), nums[i]+k)) ++res;
        }
        return res;
    }
};


// Solution 2 : sort and two pointers, O(nlogn), O(1)
class Solution_2 {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;
        for (int i = 0, j = 0; i < n; i++) {
            for (j = max(j, i+1); j < n && nums[j]-nums[i] < k; j++) ;
            if (j < n && nums[j]-nums[i] == k) res++;
            while (i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return res;
    }
};


// Solution 3 : hash table, O(n), O(n)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        unordered_map<int, int> m;
        for (int& num : nums) m[num]++;
        int res = 0;
        for (auto& p : m) {
            if (k == 0) res += p.second >= 2 ? 1 : 0;
            else res += m.count(p.first+k);
        }
        return res;
    }
};


int main() {
    vector<int> nums = {1, 1, 1, 2, 2};
    Solution_2 s2;
    cout << s2.findPairs(nums, 0) << endl;
    return 0;
}
